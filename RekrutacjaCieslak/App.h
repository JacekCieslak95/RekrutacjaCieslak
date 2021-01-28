#pragma once

#include "MathematicalOperationFactory.h"
#include "OperationSet.h"

#include <string>
#include <vector>
#include <memory>
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
