#include "Matrix.h"

#include <sstream>
#include <algorithm>

Matrix::Matrix(std::string dataString)
{
    std::vector<std::vector<double>>parsedData;
    std::string  matrixRowTmp;
    std::stringstream ss(dataString);

    while(getline(ss, matrixRowTmp, ';')) {
        parsedData.push_back(ParseRow(matrixRowTmp));
    }
    if (!CheckIfCorrectMatrix(parsedData))
        throw std::runtime_error("Provided data not correct");
    Data = parsedData;
}
Matrix::Matrix(std::vector<std::vector<double>> data)
{
    this->Data = data;
}

Matrix::Matrix(const Matrix& source)
{
    this->Data = source.Data;
}

std::string Matrix::ToString()
{
    std::stringstream output;
    bool first = true;
    for (std::vector<double> row : Data)
    {
        std::stringstream line;
        if (!first)
        {
            output << "; ";
        }
        std::copy(row.begin(), row.end() - 1,
            std::ostream_iterator<int>(line, " "));
        line << row.back();
        output << line.str();

        first = false;
    }
    return output.str();
}

Matrix Matrix::operator +(const Matrix& m)
{
    if (this->GetColsNo() != m.Data.front().size() || this->GetRowsNo() != m.Data.size())
    {
        throw std::runtime_error("Matrixes sizes are not equal");
    }

    std::vector<std::vector<double>> result;
    for (int rowIndex = 0; rowIndex < GetRowsNo(); ++rowIndex)
    {
        std::vector<double> row;
        for (int colIndex = 0; colIndex < GetColsNo(); ++colIndex)
        {
            double element = Data.at(rowIndex).at(colIndex) + m.Data.at(rowIndex).at(colIndex);
            row.push_back(element);
        }
        result.push_back(row);
    }
    return Matrix(result);
}
Matrix& Matrix::operator +=(const Matrix& m)
{
    if (this->GetColsNo() != m.Data.front().size() || this->GetRowsNo() != m.Data.size())
    {
        throw std::runtime_error("Matrixes sizes are not equal");
    }

    for (int rowIndex = 0; rowIndex < GetRowsNo(); ++rowIndex)
    {
        for (int colIndex = 0; colIndex < GetColsNo(); ++colIndex)
        {
            Data.at(rowIndex).at(colIndex) += m.Data.at(rowIndex).at(colIndex);
        }
    }
    return *this;
}


std::vector<double> Matrix::GetCol(int index)
{
    if (index >= GetColsNo())
        throw new std::runtime_error("Column index out of range");
    std::vector<double> result;
    for (std::vector<double> row : Data)
    {
        result.push_back(row.at(index));
    }
    return result;
}
std::vector<double> Matrix::GetRow(int index)
{
    if (index >= GetRowsNo())
        throw new std::runtime_error("Row index out of range");
    return Data.at(index);
}

std::vector<double> Matrix::ParseRow(std::string RowString)
{
    std::vector<double> result;
    std::stringstream ss(RowString);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> elementsStrings(begin, end);
    std::transform(elementsStrings.begin(), elementsStrings.end(), std::back_inserter(result),
        [](const std::string& str) { return std::stoi(str); });
    return result;
}
bool Matrix::CheckIfCorrectMatrix(const std::vector<std::vector<double>>& data)
{
    if (data.size() == 0)
        return false;
    bool rectangular = true;
    int elementsInFirstRow = data.front().size();
    for (std::vector<double> row : data)
    {
        rectangular &= (elementsInFirstRow == row.size());
    }
    return rectangular;
}