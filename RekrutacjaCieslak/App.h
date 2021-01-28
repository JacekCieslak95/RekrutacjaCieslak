#pragma once
#include <string>
#include <vector>
#include <memory>

#include "MathematicalOperationFactory.h"
#include "OperationSet.h"

class App
{
public:
	App(std::string inputFile, std::string outputFile);
	~App();
	void Run();
private:
	std::string InputFile;
	std::string OutputFile;

	std::vector<std::shared_ptr<OperationSet>> Operations;
	
	void ReadOperationsFromFile();
	void CalculateOperations();
	void StoreOperationsToFile();
};

