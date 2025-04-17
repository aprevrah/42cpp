#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <string>
#include <cstdlib>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {(void)other;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

double toDouble(std::string const &str) {
    if (str == "nanf" || str == "nan") {
        return std::numeric_limits<double>::quiet_NaN();
    }
    if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff") {
        return (std::numeric_limits<double>::infinity());
    }
    if (str == "-inf" || str == "-inff") {
        return (-std::numeric_limits<double>::infinity());
    }
    if (str.size() == 3 && str[0] == '\'' && str[2] == '\'') {
        return static_cast<double>(str[1]);
    }
    if (str.size() == 1 && !isdigit(str[0])) {
        return static_cast<double>(str[0]);
    }
    std::string temp = str;
    if (!temp.empty() && temp[temp.size() -1] == 'f') {
        temp = temp.substr(0, temp.size() - 1);
    }

    char *endPtr = NULL;
    double result = std::strtod(temp.c_str(), &endPtr);

    // Check if the entire string was parsed
    if (endPtr == temp.c_str() || *endPtr != '\0') {
        std::cerr << "Invalid input: " << str << std::endl;
        return std::numeric_limits<double>::quiet_NaN();  // Fallback for invalid input
    }

    return result;
}

void printChar(double value) {
    std::cout << "char: ";
    if (!std::isfinite(value))
        std::cout << "impossible";
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(value) << "'";
    std::cout << std::endl;
}

void printInt(double value) {
    std::cout << "int: ";
    if (!std::isfinite(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(value);
    std::cout << std::endl;
}

void printFloat(double value) {
    std::cout << "float: ";
    if (std::isnan(value)) {
        std::cout << "nanf";
    }
    else if (std::isinf(value)) {
        if (value > 0) {
            std::cout << "+inff";
        } else {
            std::cout << "-inff";
        }
    } else {
        if (value == static_cast<int>(value))
            std::cout << std::fixed << std::setprecision(1);
        else
            std::cout << std::fixed << std::setprecision(7);
        std::cout << static_cast<float>(value) << "f";
    }
    std::cout << std::endl;
}

void printDouble(double value) {
    std::cout << "double: ";
    if (std::isnan(value)) {
        std::cout << "nan";
    }
    else if (std::isinf(value)) {
        if (value > 0) {
            std::cout << "+inf";
        } else {
            std::cout << "-inf";
        }
    } else {
        if (value == static_cast<int>(value))
            std::cout << std::fixed << std::setprecision(1);
        else
            std::cout << std::fixed << std::setprecision(15);
        std::cout << value;
    }
    std::cout << std::endl;
}

void ScalarConverter::convert(std::string const &scalar) {
    double value;
    value = toDouble(scalar);

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
