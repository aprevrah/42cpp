#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name(other.name) {
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
    if (this != &rhs) {
        this->grade = rhs.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string const &Bureaucrat::getName() const { 
    return (this->name);
}

int Bureaucrat::getGrade() const {
    return (this->grade);
}

void Bureaucrat::incrementGrade() {
    if (this->grade <= 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->grade >= 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade++;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}