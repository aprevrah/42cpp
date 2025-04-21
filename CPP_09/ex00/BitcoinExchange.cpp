#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <ctime>
#include <string>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

// BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) {
// 	(void)other;
// }

// BitcoinExchange BitcoinExchange::operator=(BitcoinExchange const &rhs) {
// 	(void)rhs;
// }

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string& date) {
    std::tm tm = {};
    char* result = strptime(date.c_str(), "%Y-%m-%d", &tm);

    // strptime returns a null pointer if the parsing fails
    if (result == NULL) {
        return false;
    }

    // Additional check: Ensure the entire string was consumed
    if (*result != '\0') {
        return false;
    }

   // Extract year, month, and day
   int year = tm.tm_year + 1900;
   int month = tm.tm_mon + 1; // tm_mon is 0-based
   int day = tm.tm_mday;
   DEBUG_PRINT(year << "-" << month << "-" << day);

   // Validate year, month, and day ranges
   if (year < 1900 || month < 1 || month > 12 || day < 1) {
	   return false;
   }

   // Days in each month
   int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   // Check for leap year
   bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
   if (isLeapYear && month == 2) {
	   daysInMonth[1] = 29; // February has 29 days in a leap year
   }

   // Validate the day against the number of days in the month
   if (day > daysInMonth[month - 1]) {
	   return false;
   }

   return true;
}

void BitcoinExchange::loadDataMap(std::ifstream& dataFstream) {
	dataMap.clear();
    std::string line;

    while (getline(dataFstream, line)) {
        std::istringstream ss(line);
        std::string date;
        double value;

        if (getline(ss, date, ',') && ss >> value) {
            this->dataMap[date] = value; // Insert into the map
        } else {
            std::cerr << "Error: Malformed line in data file: " << line << std::endl;
        }
    }
}

void BitcoinExchange::printResults(std::ifstream &inputFile)
{
	std::string line;
	while (getline(inputFile, line)) {
		std::istringstream ss(line);
        std::string date;
        double value;
		DEBUG_PRINT(line);

        if (getline(ss, date, '|') && ss >> value) {

			if (value < 0) {
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
			if (value > 1000) {
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}

			for (std::map<std::string, double>::reverse_iterator it = dataMap.rbegin(); it != dataMap.rend(); ++it) {
				if (it->first <= date) {
					DEBUG_PRINT(it->first << "," << it->second);
					DEBUG_PRINT(it->first << " <= " << date);
					DEBUG_PRINT(value << " * " << it->second << " = " << it->second * value);
					std::cout << date << " => " << value << " = " << it->second * value << std::endl;
					break;
				}
			}
		}
		else {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		DEBUG_PRINT("---");
	}
}