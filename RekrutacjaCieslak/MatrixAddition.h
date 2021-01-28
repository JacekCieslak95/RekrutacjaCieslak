#pragma once
#include <string>
#include <vector>

#include "AbstractMathematicalOperation.h"
#include "Matrix.h"

class MatrixAddition : public AbstractMathematicalOperation
{
public:
	MatrixAddition();
	std::string GetClassName() override;
	inline static std::string GetClassStaticName() { return Name; }
	std::string Proceed() override;
	void SetArguments(std::vector<std::string> arguments) override;
	std::vector<std::string> GetArguments() override;
private:
	std::vector<Matrix> StoredArguments;
	bool IfSameSize(std::vector<Matrix> matrixes);
	bool IfSameSize(Matrix* A, Matrix* B);
	inline static const std::string Name = "Matrix Addition";
};
