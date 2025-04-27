#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <ctime>
#include <sstream>



int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <input.txt>" << std::endl;
		return 1;
	}
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open input file\n";
		return 1;
	}
	std::ifstream dataFile("data.csv");
	if (!dataFile.is_open()) {
		std::cerr << "Error: Could not open data.csv\n";
		return 1;
	}
	
	BitcoinExchange ex;
	ex.loadDataMap(dataFile);
	ex.printResults(inputFile);
 	
    return 0;
}

// bool checkDate(const std::string &date) {
// 	if (BitcoinExchange::isValidDate(date)) {
// 		std::cout << date << " is VALID" << std::endl;
// 		return true;
// 	}
// 	std::cout << date << " is BAD" << std::endl;
// 		return false;
// }

// Example: Print the map contents
// for (std::map<std::string, double>::iterator it = dataMap.begin(); it != dataMap.end(); ++it) {
//     std::cout << it->first << ": " << it->second << std::endl;
// }

// test
// checkDate("2025-2-31");
// checkDate("2025-2-10");

// checkDate("2024-2-29");
// checkDate("2025-2-29");