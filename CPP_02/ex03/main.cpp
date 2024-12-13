#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	const Point a(0, 0);
	const Point b(4, 6);
	const Point c(5, 0);

	const Point points[] = {
		Point(1, 1),
		Point(5, 4.5f),
        Point(3, 0.01f),
        Point(3, 0.0f),
		Point(4.5f, 2.25f)
	};

	std::cout << YELLOW << "Triangle: " << RESET
              << BLUE << "a" << a << ", "
              << "b" << b << ", "
              << "c" << c << RESET << std::endl;

    for (unsigned long i = 0; i < sizeof(points) / sizeof(Point); ++i) {
        std::cout << std::endl << "Point " << i + 1 << ": "
                  << BLUE << points[i] << RESET << std::endl;

        if (bsp(a, b, c, points[i])) {
            std::cout << GREEN << "IS in the triangle" << RESET << std::endl;
        } else {
            std::cout << RED << "Is NOT in the triangle" << RESET << std::endl;
        }
    }
}
