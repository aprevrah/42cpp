#pragma once
#include <ostream>
#include <iostream>
#include "Fixed.hpp"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class Point {
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& point);
		~Point();
		Point&	operator=(const Point& rhs);
		
		const Fixed& getX() const;
		const Fixed& getY() const;
};

std::ostream& operator<<(std::ostream& os, const Point& point);