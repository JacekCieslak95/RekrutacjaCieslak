#pragma once
#include <string>
#include <vector>

class AbstractMathematicalOperation
{
public:
	virtual ~AbstractMathematicalOperation() {}
	virtual std::string GetClassName() = 0;
	virtual std::string Proceed() = 0;
	virtual void SetArguments(std::vector<std::string> arguments) = 0;
	virtual std::vector<std::string> GetArguments() = 0;
};
