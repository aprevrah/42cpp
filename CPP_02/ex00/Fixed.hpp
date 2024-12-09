#pragma once

class Fixed {
	private:
		int value;
		static const int fbits = 8;
	public:
		Fixed();
		Fixed(const Fixed& fixed);
		~Fixed();
		Fixed&	operator=(const Fixed& rhs);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};