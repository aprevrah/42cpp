#include <ostream>
#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}
Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}
Point::Point(const Point& other) : x(other.getX()), y(other.getY()) {}
Point::~Point() {}
/* 
Point& Point::operator=(const Point& rhs) {
	if (this != &rhs) {
		this->x = rhs.getX();
		this->y = rhs.getY();
	}
	return *this;
} */

const Fixed& Point::getX() const {return x;}

const Fixed& Point::getY() const {return y;}

std::ostream& operator<<(std::ostream& os, const Point& point) {
	os << "(" << point.getX() << ", " << point.getY() << ")";
    return os;
}