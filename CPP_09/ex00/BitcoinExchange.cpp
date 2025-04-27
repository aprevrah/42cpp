#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <ctime>
#include <string>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

// BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) {
// 	(void)other;
// }

// BitcoinExchange BitcoinExchange::operator=(BitcoinExchange const &rhs) {
// 	(void)rhs;
// }

BitcoinExchange::~BitcoinExchange() {}

std::string trim(std::string const &str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    std::tm tm = {};
    strptime(date.c_str(), "%Y-%m-%d", &tm);
    time_t epoch_time = mktime(&tm);
    std::tm* tm_ptr = std::localtime(&epoch_time);
    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm_ptr);
    return (std::string(buffer) == date);
}

/* bool BitcoinExchange::isValidDate(const std::string& date) {
    std::tm tm = {};
    char* result = strptime(date.c_str(), "%Y-%m-%d", &tm);

    // strptime returns a null pointer if the parsing fails
    if (result == NULL) {
        return false;
    }

    // Additional check: Ensure the entire string was consumed
    // if (*result != '\0') {
    //     return false;
    // }

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
} */

bool BitcoinExchange::parseLine(const std::string &line, char separator, std::string &date, double &value) {
    size_t separatorPos = line.find(separator);
    if (separatorPos == std::string::npos) {
        std::cerr << "Error: Missing separator in line => " << line << std::endl;
        return false;
    }

    date = trim(line.substr(0, separatorPos));
    std::string valueStr = trim(line.substr(separatorPos + 1));

    //Date
    if (!isValidDate(date)) {
        std::cerr << "Error: Invalid date => " << date << std::endl;
        return false;
    }
    //Value
    char* endPtr = NULL;
    value = std::strtod(valueStr.c_str(), &endPtr);
    if (*endPtr != '\0' || valueStr.empty()) {
        std::cerr << "Error: Invalid value => " << valueStr << std::endl;
        return false;
    }

    return true;
}

void BitcoinExchange::loadDataMap(std::ifstream& dataFstream) {
	dataMap.clear();
    std::string line;
    unsigned int l_nbr = 0;

    if (getline(dataFstream, line)) {
        l_nbr++;
        if (line != "date,exchange_rate") {
            std::cerr << "Error: Bad header in data.csv" << std::endl;
            return;
        }
    }

    while (getline(dataFstream, line)) {
        l_nbr++;
        
        std::string date;
        double value;
        if (parseLine(line, ',', date, value)) {
            this->dataMap[date] = value;
        } else {
            std::cerr << "Error: line " << l_nbr <<  " of data file: " << line << std::endl;
        }
    }
}

/* 
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
            if (dataMap.begin()->first > date) {
                std::cerr << "Error: date is before database." << std::endl;
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
 */


 void BitcoinExchange::printResults(std::ifstream &inputFile) {
    std::string line;
    unsigned int l_nbr = 0;

    if (getline(inputFile, line)) {
        l_nbr++;
        if (line != "date | value") {
            std::cerr << "Error: Bad header in input file" << std::endl;
            return;
        }
    }

    while (getline(inputFile, line)) {
        l_nbr++;

        std::string date;
        double value;
        if (parseLine(line, '|', date, value)) {
            if (value < 0) {
                std::cerr << "Error: Not a positive number => " << value << std::endl;
                continue;
            }
            if (value > 1000) {
                std::cerr << "Error: Too large a number => " << value << std::endl;
                continue;
            }
            if (dataMap.begin()->first > date) {
                std::cerr << "Error: Date is before database => " << date << std::endl;
                continue;
            }

            std::map<std::string, double>::iterator it = dataMap.upper_bound(date);
            it--;
            std::cout << date << " => " << value << " = " << it->second * value << std::endl;
        } else {
            std::cerr << "Error: Failed to parse line " << l_nbr << " => " << line << std::endl;
        }
    }
}