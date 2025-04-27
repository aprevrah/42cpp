#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <ctime>
#include <fstream>

//#define DEBUG //comment to diable debugging
#ifdef DEBUG
    #define DEBUG_PRINT(x) std::cerr << "[DEBUG] " << x << std::endl
#else
    #define DEBUG_PRINT(x)
#endif

class BitcoinExchange {
	private:
		std::map<std::string, double> dataMap;
	public:
	BitcoinExchange();
	BitcoinExchange(std::ifstream dataFile);
	BitcoinExchange(BitcoinExchange const &other);
	BitcoinExchange operator=(BitcoinExchange const &rhs);
	~BitcoinExchange();
	
	static bool parseLine(const std::string &line, char separator, std::string &date, double &value);
	static bool isValidDate(const std::string& date);
	void loadDataMap(std::ifstream& dataFstream);
	void printResults(std::ifstream &inputFstream);
	void openFile(std::string data, std::string input) const;
};