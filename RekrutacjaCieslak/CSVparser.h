#pragma once
#include <string>
#include <vector>

class CSVparser
{
public:
	static CSVparser* GetInstance();

	std::vector<std::vector<std::string>> ReadFileLines(std::string fileName);
	void SaveToFile(std::string fileName, std::vector<std::vector<std::string>> data);
private:
	CSVparser() {};
	inline static CSVparser* instance = nullptr;;
	std::vector<std::string> ParseLine(std::string line);
};

