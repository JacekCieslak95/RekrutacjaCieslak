#pragma once
#include "AbstractMathematicalOperation.h"
#include "ArithmeticAddition.h"
#include "ArithmeticMultiplication.h"
#include "MatrixAddition.h"
class MathematicalOperationFactory
{
public:
	static MathematicalOperationFactory* GetInstance();
	AbstractMathematicalOperation* CreateOperation(std::string OperationName);

	inline AbstractMathematicalOperation* CreateArithmeticAddition() { return new ArithmeticAddition(); }
	inline AbstractMathematicalOperation* CreateArithmeticMultiplication() { return new ArithmeticMultiplication(); }
	inline AbstractMathematicalOperation* CreateMatrixAddition() { return new MatrixAddition(); }

private:
	MathematicalOperationFactory() {};
	inline static MathematicalOperationFactory* instance = nullptr;;
};

