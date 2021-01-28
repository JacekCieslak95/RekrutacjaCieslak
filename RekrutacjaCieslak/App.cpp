#include "App.h"
#include "CSVparser.h"

App::App(std::string inputFile, std::string outputFile)
{
	InputFile = inputFile;
	OutputFile = outputFile;
}
App::~App()
{}
void App::Run()
{
	ReadOperationsFromFile();
	CalculateOperations();
	StoreOperationsToFile();
}

void App::ReadOperationsFromFile()
{
	auto parsedLines = CSVparser::GetInstance()->ReadFileLines(InputFile);
	for (auto line : parsedLines)
	{
		std::shared_ptr<OperationSet> ptr(new OperationSet(line));
		Operations.push_back(ptr);
	}
}
void App::CalculateOperations()
{
	for (auto op : Operations)
	{
		if (!op->Details.Pass)
			continue;
		try
		{
			op->Details.Result = op->Operation->Proceed();
		}
		catch (std::exception e)
		{
			op->Details.Result = e.what();
			op->Details.Pass = false;
		}
	}
}
void App::StoreOperationsToFile()
{
	std::vector<std::vector<std::string>> FullResult;
	for (auto op : Operations)
	{
		FullResult.push_back(op->Details.ToStringVector());
	}
	CSVparser::GetInstance()->SaveToFile(OutputFile, FullResult);
}