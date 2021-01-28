#include "OperationSet.h"
#include "MathematicalOperationFactory.h"
#include <stdexcept>
#include <numeric>

OperationDetails::OperationDetails(std::vector<std::string> AllData)
{
	OperationName = AllData.front();
	std::copy(AllData.begin() + 1, AllData.end(),
		std::back_inserter(Arguments));
}
std::vector<std::string> OperationDetails::ToStringVector()
{
	std::vector<std::string> output;
	output.push_back(OperationName);
	output.push_back(Pass? "PASS" : "FAIL");
	output.push_back(Result);
	output.insert(output.end(), Arguments.begin(), Arguments.end());
	return output;
}

OperationSet::OperationSet(std::vector<std::string> AllOperationData) : Details(AllOperationData)
{
	try
	{
		Operation = MathematicalOperationFactory::GetInstance()->CreateOperation(Details.OperationName);
		Operation->SetArguments(Details.Arguments);
	}
	catch(std::exception e)
	{
		Details.Result = e.what();
		Details.Pass = false;
	}

}
OperationSet::~OperationSet()
{
	delete Operation;
}
