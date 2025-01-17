#pragma once
#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const name_;
        int const gradeSign_;
        int const gradeExecute_;
        bool isSigned_;
    public:
        AForm(std::string const name, int gradeSign, int gradeExecute);
        AForm(AForm const &other);
        AForm &operator=(AForm const &rhs);
        virtual ~AForm();

        std::string const &getName() const;
        int getGradeSign() const;
        int getGradeExecute() const;
        bool getIsSigned() const;
        void beSigned(Bureaucrat &bureaucrat);
        void execute(const Bureaucrat &executor) const;
        virtual void executeAction(const Bureaucrat &executor) const = 0;

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

std::ostream &operator<<(std::ostream &out, AForm const &form);