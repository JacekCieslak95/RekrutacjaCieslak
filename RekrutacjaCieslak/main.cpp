#include "App.h"

#include <iostream>

int main()
{
	std::string inputFile, outputFile;
	std::cout << "Specify input file: ";
	std::cin >> inputFile;
	std::cout << "Specify output file: ";
	std::cin >> outputFile;

	App app(inputFile, outputFile);
	app.Run();
	return 0;
}