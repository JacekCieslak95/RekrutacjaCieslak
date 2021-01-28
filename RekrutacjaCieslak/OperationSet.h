#pragma once
#include "AbstractMathematicalOperation.h"

#include <string>
#include <vector>

struct OperationDetails
{
	std::string OperationName;
	std::vector<std::string> Arguments;
	std::string Result = "";
	bool Pass = true;

	OperationDetails(std::vector<std::string> AllData);
	std::vector<std::string> ToStringVector();
};


class OperationSet
{
public:
	OperationSet(std::vector<std::string> AllOperationData);
	~OperationSet();
	OperationDetails Details;
	AbstractMathematicalOperation* Operation;
};

