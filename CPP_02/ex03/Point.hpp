#pragma once
#include <ostream>
#include <iostream>
#include "Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point point);
		~Point();
		Point&	operator=(const Point& rhs);
		
		Fixed getX();
		Fixed getY();
};
