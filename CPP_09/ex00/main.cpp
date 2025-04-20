#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <ctime>
#include <sstream>

int main(int argc, char **argv) {
	BitcoinExchange ex;
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <input.txt>" << std::endl;
	}
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open input file\n";
		return 1;
	}
	std::ifstream dataFile("data.csv");
	if (!dataFile.is_open()) {
		std::cerr << "Error: Could not open data\n";
		return 1;
	}
	
	// std::string line;
	// while (getline(dataFile, line)) {
		
	// 	std::cout << line << std::endl;
	// }

	std::map<std::string, double> dataMap; // Map to store date and value
    std::string line;

    while (getline(dataFile, line)) {
        std::istringstream ss(line);
        std::string date;
        double value;

        if (getline(ss, date, ',') && ss >> value) {
            dataMap[date] = value; // Insert into the map
        } else {
            std::cerr << "Error: Malformed line in data file: " << line << std::endl;
        }
    }

    // Example: Print the map contents
    for (std::map<std::string, double>::iterator it = dataMap.begin(); it != dataMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
	//std::cout << __FUNCTION__ << std::endl;
}

