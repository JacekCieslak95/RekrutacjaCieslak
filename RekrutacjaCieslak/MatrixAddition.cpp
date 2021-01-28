#include "MatrixAddition.h"

#include <stdexcept>

MatrixAddition::MatrixAddition() {}
std::string MatrixAddition::GetClassName() { return Name; }

std::string MatrixAddition::Proceed()
{
	if (StoredArguments.size() == 0)
		throw std::runtime_error("No arguments stored");

	Matrix sum = StoredArguments.front();
	bool first = true;
	for (Matrix m : StoredArguments)
	{
		if (first)
		{
			first = false;
			continue;
		}

		sum += m;
	}
	return sum.ToString();
}
void MatrixAddition::SetArguments(std::vector<std::string> arguments)
{
	if (arguments.size() == 0)
		throw std::runtime_error("No arguments passed");

	std::vector<Matrix> ProcessedArguments;
	for (std::string singleArgument : arguments)
	{
		Matrix m(singleArgument);
		ProcessedArguments.push_back(m);
	}
	if (!IfSameSize(ProcessedArguments))
		throw std::runtime_error("Matrixes sizes are not equal");
	StoredArguments = ProcessedArguments;
}
std::vector<std::string> MatrixAddition::GetArguments()
{
	std::vector<std::string> resultVector;
	for (Matrix m : StoredArguments)
	{
		resultVector.push_back(m.ToString());
	}
	return resultVector;
}

bool MatrixAddition::IfSameSize(std::vector<Matrix> matrixes)
{
	Matrix* firstM = &matrixes.front();
	for (Matrix m : matrixes)
	{
		if (!IfSameSize(&m, firstM))
			return false;
	}
	return true;
}
bool MatrixAddition::IfSameSize(Matrix* A, Matrix* B)
{
	return A->GetColsNo() == B->GetColsNo() && A->GetRowsNo() == B->GetRowsNo();
}