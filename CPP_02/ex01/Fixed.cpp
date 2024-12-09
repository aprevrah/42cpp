#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// constructors

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) : value(fixed.value) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	value = n << fbits;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	 value = static_cast<int>(roundf(f * (1 << fbits)));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// operator overloads

Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->value = rhs.getRawBits();
	}
	return *this;
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

// overlaods <<
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
    return os;
}

/*
$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
$>
*/