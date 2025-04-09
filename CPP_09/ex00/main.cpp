#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <input.csv>" << std::endl;
	}
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open input file";
		return 1;
	}
	std::cout << __FUNCTION__ << std::endl;
}