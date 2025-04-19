#include <iostream>
#include "iter.hpp"

void add_three(int &i) {
    i += 3;
}

void half(double &d) {
    d *= 0.5;
}

void awesome(std::string &s) {
    s = "awesome " + s;
}

template <typename T>
void print(T &t) {
    std::cout << t << std::endl;
}

int main( void ) {
    int int_array[] = {1, 2, 3, 4, 5};
    double double_array[] = {1, 2, 3, 4, 5};
    std::string string_array[] = {"one", "two", "three", "four", "five"};

    iter(int_array, 5, add_three);
    iter(int_array, 5, print<int>);

    iter(double_array, 5, half);
    iter(double_array, 5, print<double>);

    iter(string_array, 5, awesome);
    iter(string_array, 5, print<std::string>);
    return 0;
}

/* 
class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
} */