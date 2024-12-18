#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	{
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}
	{
		Fixed a(4);
		Fixed b(2);
		std::cout << a << " - " << b << " = " << a-b << std::endl;
		std::cout << a << " + " << b << " = " << a+b << std::endl;
		std::cout << a << " * " << b << " = " << a*b << std::endl;
		std::cout << a << " / " << b << " = " << a/b << std::endl;

		std::cout << a << " == " << b << " = " << (a==b) << std::endl;
		std::cout << a << " == " << a << " = " << (a==a) << std::endl;

		std::cout << a << " != " << b << " = " << (a!=b) << std::endl;
		std::cout << a << " != " << a << " = " << (a!=a) << std::endl;

		std::cout << a << " < " << b << " = " << (a<b) << std::endl;
		std::cout << a << " < " << a << " = " << (a<a) << std::endl;
		std::cout << b << " < " << a << " = " << (b<a) << std::endl;

		std::cout << a << " > " << b << " = " << (a>b) << std::endl;
		std::cout << a << " > " << a << " = " << (a>a) << std::endl;
		std::cout << b << " > " << a << " = " << (b>a) << std::endl;

		std::cout << a << " <= " << b << " = " << (a<=b) << std::endl;
		std::cout << a << " <= " << a << " = " << (a<=a) << std::endl;
		std::cout << b << " <= " << a << " = " << (b<=a) << std::endl;

		std::cout << a << " >= " << b << " = " << (a>=b) << std::endl;
		std::cout << a << " >= " << a << " = " << (a>=a) << std::endl;
		std::cout << b << " >= " << a << " = " << (b>=a) << std::endl;
	}
	return (0);
}
