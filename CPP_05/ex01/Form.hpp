#pragma once
#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const name_;
        int const gradeSign_;
        int const gradeExecute_;
        bool isSigned_;
    public:
        Form();
        Form(std::string const name, int gradeSign, int gradeExecute);
        Form(Form const &other);
        Form &operator=(Form const &rhs);
        ~Form();

        std::string const &getName() const;
        int getGradeSign() const;
        int getGradeExecute() const;
        bool getIsSigned() const;
        void beSigned(Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream &out, Form const &form);