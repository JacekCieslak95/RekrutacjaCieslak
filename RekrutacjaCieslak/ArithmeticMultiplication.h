#pragma once
#include "AbstractMathematicalOperation.h"

#include <string>
#include <vector>

class ArithmeticMultiplication : public AbstractMathematicalOperation
{
public:
	ArithmeticMultiplication();
	std::string GetClassName() override;
	inline static std::string GetClassStaticName() { return Name; }
	std::string Proceed() override;
	void SetArguments(std::vector<std::string> arguments) override;
	std::vector<std::string> GetArguments() override;
private:
	std::vector<double> StoredArguments;
	inline static const std::string Name = "Artmetic Multiplication";
};
