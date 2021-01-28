#include <numeric>
#include <stdexcept>
#include <functional>

#include "ArithmeticMultiplication.h"

ArithmeticMultiplication::ArithmeticMultiplication(){}
std::string ArithmeticMultiplication::GetClassName() { return Name; }

std::string ArithmeticMultiplication::Proceed()
{
	if (StoredArguments.size() == 0)
		throw std::runtime_error("No arguments stored");

	auto result = std::accumulate(std::begin(StoredArguments), std::end(StoredArguments), 1, std::multiplies<>());
	return std::to_string(result);
}
void ArithmeticMultiplication::SetArguments(std::vector<std::string> arguments)
{
	if (arguments.size() == 0)
		throw std::runtime_error("No arguments passed");

	std::vector<double> ProcessedArguments;
	for (std::string singleArgument : arguments)
	{
		double parsedValue = std::stod(singleArgument);
		ProcessedArguments.push_back(parsedValue);
	}
	StoredArguments = ProcessedArguments;
}
std::vector<std::string> ArithmeticMultiplication::GetArguments()
{
	std::vector<std::string> resultVector;
	for (double singleArgument : StoredArguments)
	{
		resultVector.push_back(std::to_string(singleArgument));
	}
	return resultVector;
}