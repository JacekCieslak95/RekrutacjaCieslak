#include "MathematicalOperationFactory.h"
#include <stdexcept>
MathematicalOperationFactory* MathematicalOperationFactory::GetInstance()
{
    if (instance == nullptr) {
        instance = new MathematicalOperationFactory();
    }
    return instance;
}

AbstractMathematicalOperation* MathematicalOperationFactory::CreateOperation(std::string OperationName)
{
    if (!OperationName.compare(ArithmeticAddition::GetClassStaticName())) {
        return CreateArithmeticAddition();
    }
    else if (!OperationName.compare(ArithmeticMultiplication::GetClassStaticName())) {
        return CreateArithmeticMultiplication();
    }
    else if (!OperationName.compare(MatrixAddition::GetClassStaticName())) {
        return CreateMatrixAddition();
    }
    else
    {
        throw std::runtime_error("Unknown operation: " + OperationName);
    }
}