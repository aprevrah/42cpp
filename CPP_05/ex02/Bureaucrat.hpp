#pragma once
#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        std::string const name_;
        int grade_;
    public:
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat &operator=(Bureaucrat const &rhs);
        ~Bureaucrat();

        std::string const &getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        void signForm(AForm &form);

        class GradeTooLowException : public std::exception
        {
            public:
               virtual const char *what() const throw();
        };
        class GradeTooHighException : public std::exception
        {
            public:
               virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);