#pragma once
#include <string>

class BitcoinExcange {
	private:
	public:
	BitcoinExcange();
	BitcoinExcange(BitcoinExcange const &other);
	BitcoinExcange operator=(BitcoinExcange const &rhs);
	~BitcoinExcange();
	
	void doTheThing(std::string data, std::string input) const;
};