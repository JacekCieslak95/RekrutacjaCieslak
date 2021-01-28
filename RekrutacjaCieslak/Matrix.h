#pragma once
#include <string>
#include <vector>

class Matrix
{
public:
	Matrix(std::string dataString);
	Matrix(std::vector<std::vector<double>> data);
	Matrix(const Matrix& source);
	inline int GetRowsNo() { return Data.size(); }
	inline int GetColsNo() { return Data.front().size(); }
	
	std::vector<double> GetCol(int index);
	std::vector<double> GetRow(int index);
	std::string ToString();

	Matrix operator + (const Matrix& m);
	Matrix& operator +=(const Matrix& m);


private:
	std::vector<std::vector<double>> Data;

	std::vector<double> ParseRow(std::string RowString);
	bool CheckIfCorrectMatrix(const std::vector<std::vector<double>>& data);
};

