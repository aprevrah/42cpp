#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// constructors

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const Fixed& fixed) : value(fixed.value) {}

Fixed::Fixed(const int n) {
	value = n << fbits;
}

Fixed::Fixed(const float f) {
	 value = static_cast<int>(roundf(f * (1 << fbits)));
}

Fixed::~Fixed() {}

// operator overloads

Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->value = rhs.getRawBits();
	}
	return *this;
}

// comparison operators

bool Fixed::operator>(const Fixed& rhs) const {
	return value > rhs.value;
}

bool Fixed::operator<(const Fixed& rhs) const {
	return value < rhs.value;
}

bool Fixed::operator>=(const Fixed& rhs) const {
	return value >= rhs.value;
}

bool Fixed::operator<=(const Fixed& rhs) const {
	return value <= rhs.value;
}

bool Fixed::operator==(const Fixed& rhs) const {
	return value == rhs.value;
}

bool Fixed::operator!=(const Fixed& rhs) const {
	return value != rhs.value;
}

// arithmetic operators

Fixed	Fixed::operator+(const Fixed& rhs) const {
	Fixed result;
	result.value = value + rhs.value;
	return result;
}

Fixed	Fixed::operator-(const Fixed& rhs) const {
	Fixed result;
	result.value = value - rhs.value;
	return result;
}

Fixed	Fixed::operator*(const Fixed& rhs) const {
	Fixed result;
	result.value = (value * rhs.value) >> fbits;
	return result;
}

Fixed	Fixed::operator/(const Fixed& rhs) const {
	Fixed result;
	result.value = (value << fbits) / rhs.value;
	return result;
}

// Pre-increment
Fixed&	Fixed::operator++() { 
	value++;
	return *this;
}
// Post-increment
Fixed	Fixed::operator++(int) {
	Fixed old(*this);
	value++;
	return old;
}     

// Pre-decrement
Fixed&	Fixed::operator--() {
	value--;
	return *this;
}

// Post-decrement
Fixed	Fixed::operator--(int) {     
	Fixed old(*this);
	value++;
	return old;
}

// member functions
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

int Fixed::toInt( void ) const {
	return roundf(value >> fbits);
}

float Fixed::toFloat( void ) const {
	return value * 1.0f / (1 << fbits);
}

// static member functions

Fixed& Fixed::min(Fixed& fixed_a, Fixed& fixed_b) {
	if (fixed_a < fixed_b)
		return fixed_a;
	return fixed_b;
}

const Fixed& Fixed::min(const Fixed& fixed_a, const Fixed& fixed_b) {
	if (fixed_a < fixed_b)
		return fixed_a;
	return fixed_b;
}

Fixed& Fixed::max(Fixed& fixed_a, Fixed& fixed_b) {
	if (fixed_a > fixed_b)
		return fixed_a;
	return fixed_b;
}

const Fixed& Fixed::max(const Fixed& fixed_a, const Fixed& fixed_b) {
	if (fixed_a > fixed_b)
		return fixed_a;
	return fixed_b;
}


// << overlaod
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
    return os;
}
