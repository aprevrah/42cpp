#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    {
        //default constructor
        Bureaucrat b_0;
        std::cout << b_0 << std::endl;
        //parameterized constructor
        Bureaucrat b_1("Bob", 20);
        std::cout << b_1 << std::endl;
        //copy constructor
        Bureaucrat b_2(b_1);
        std::cout << b_2 << std::endl;
        //parameterized constructor
        Bureaucrat b_3("Alice", 30);
        std::cout << b_3 << std::endl;
        //copy assignment operator
        b_3 = b_1;
        std::cout << b_3 << std::endl;
    }

    {
        try {
            Bureaucrat b("James", 0);
        } catch (Bureaucrat::GradeTooHighException &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    {
        try {
            Bureaucrat b("James", 151);
        } catch (Bureaucrat::GradeTooLowException &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    {
        try {
            Bureaucrat b("James", 1);
            b.incrementGrade();
        } catch (Bureaucrat::GradeTooHighException &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    {
        try {
            Bureaucrat b("James", 150);
            b.decrementGrade();
        } catch (Bureaucrat::GradeTooLowException &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    {
        Bureaucrat b("James", 10);
        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
    }

    {
        Bureaucrat *b = new Bureaucrat("Jonny", 1);
        std::cout << b->getName() << std::endl;
        std::cout << b->getGrade() << std::endl;
        delete b;
    }
    return (0);
}