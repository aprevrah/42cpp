#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <ctime>

class BitcoinExchange {
	private:
		std::map<time_t, int> data;
	public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &other);
	BitcoinExchange operator=(BitcoinExchange const &rhs);
	~BitcoinExchange();
	
	void openFile(std::string data, std::string input) const;
};