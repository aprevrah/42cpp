#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("Default Bureaucrat"), grade_(150) {}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name_(name) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade_ = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name_(other.name_) {
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
    if (this != &rhs) {
        this->grade_ = rhs.grade_;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string const &Bureaucrat::getName() const { 
    return (this->name_);
}

int Bureaucrat::getGrade() const {
    return (this->grade_);
}

void Bureaucrat::incrementGrade() {
    if (this->grade_ <= 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade_--;
}

void Bureaucrat::decrementGrade() {
    if (this->grade_ >= 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade_++;
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << name_ << " signed " << form.getName() << std::endl;
    } catch (const Form::GradeTooLowException &e) {
        std::cout << name_ << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
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