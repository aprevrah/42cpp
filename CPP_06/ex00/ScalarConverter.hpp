#pragma once
#include <string>
#include <iostream>

class ScalarConverter
{
    private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &other);
    ScalarConverter &operator=(ScalarConverter const &rhs);
    ~ScalarConverter();

    public:
    static void convert(std::string const &scalar);
};