#pragma once
#include <ostream>
#include <iostream>

class Fixed {
	private:
		int value;
		static const int fbits = 8;
	public:
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed(const int n);
		Fixed(const float f);
		~Fixed();

		Fixed&	operator=(const Fixed& rhs);

		bool 	operator>(const Fixed& rhs) const;
		bool	operator<(const Fixed& rhs) const;
		bool	operator>=(const Fixed& rhs) const;
		bool	operator<=(const Fixed& rhs) const;
		bool	operator==(const Fixed& rhs) const;
		bool	operator!=(const Fixed& rhs) const;

		Fixed	operator+(const Fixed& rhs) const;
		Fixed	operator-(const Fixed& rhs) const;
		Fixed	operator*(const Fixed& rhs) const;
		Fixed	operator/(const Fixed& rhs) const;

		Fixed&	operator++();		// Pre-increment
		Fixed	operator++(int);	// Post-increment
		Fixed&	operator--();		// Pre-decrement
		Fixed	operator--(int);	// Post-decrement
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		
		int		toInt( void ) const;
		float	toFloat( void ) const;

		static Fixed&	min(Fixed& fixed_a, Fixed& fixed_b);
		static const Fixed&	min(Fixed const& fixed_a, Fixed const& fixed_b);
		static Fixed&	max(Fixed& fixed_a, Fixed& fixed_b);
		static const Fixed&	max(Fixed const& fixed_a, Fixed const& fixed_b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);