#include "ArithmeticAddition.h"

#include <numeric>
#include <stdexcept>

ArithmeticAddition::ArithmeticAddition() {}
std::string ArithmeticAddition::GetClassName() { return Name; }

std::string ArithmeticAddition::Proceed()
{
	if (StoredArguments.size() == 0)
		throw std::runtime_error("No arguments stored");

	auto sum = std::accumulate(StoredArguments.begin(), StoredArguments.end(),
		decltype(StoredArguments)::value_type(0));
	return std::to_string(sum);
}
void ArithmeticAddition::SetArguments(std::vector<std::string> arguments)
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
std::vector<std::string> ArithmeticAddition::GetArguments()
{
	std::vector<std::string> resultVector;
	for (double singleArgument : StoredArguments)
	{
		resultVector.push_back(std::to_string(singleArgument));
	}
	return resultVector;
}