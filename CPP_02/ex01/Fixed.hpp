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

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		
		int		toInt( void ) const;
		float	toFloat( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);