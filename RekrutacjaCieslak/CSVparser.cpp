#include "CSVparser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <numeric>

CSVparser* CSVparser::GetInstance()
{
	if (instance == nullptr) {
		instance = new CSVparser();
	}
	return instance;
}

std::vector<std::vector<std::string>> CSVparser::ReadFileLines(std::string fileName)
{
	std::ifstream inputStream(fileName);
	std::vector<std::vector<std::string>> result;
	std::string line;
	while (std::getline(inputStream, line))
		result.push_back(ParseLine(line));
	return result;
}
std::vector<std::string> CSVparser::ParseLine(std::string line)
{
	std::vector<std::string>parsedData;
	std::string  element;
	std::stringstream ss(line);

	while (getline(ss, element, ',')) {
		parsedData.push_back(element);
	}
	return parsedData;
}

void CSVparser::SaveToFile(std::string fileName, std::vector<std::vector<std::string>> data)
{
	std::ofstream outputStream(fileName);
	for (std::vector<std::string> row : data)
	{
		std::string line = std::accumulate(std::begin(row), std::end(row), std::string(),
			[](std::string& ss, std::string& s)
			{
				return ss.empty() ? s : ss + ", " + s;
			});
		outputStream << line << std::endl;
	}
	outputStream.close();
}