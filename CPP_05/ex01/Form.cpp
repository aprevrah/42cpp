#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

Form::Form(std::string const name, int gradeSign, int gradeExecute)
    : name_(name), gradeSign_(gradeSign), gradeExecute_(gradeExecute), isSigned_(false) {
    if (gradeSign < 1 || gradeExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeSign > 150 || gradeExecute > 150) {
        throw GradeTooLowException();
    }
}

Form::Form(Form const &other)
    : name_(other.name_), gradeSign_(other.gradeSign_), gradeExecute_(other.gradeExecute_), isSigned_(other.isSigned_) {}

Form &Form::operator=(Form const &rhs) {
    if (this != &rhs) {
        this->isSigned_ = rhs.isSigned_;
    }
    return (*this);
}

Form::~Form() {}

std::string const &Form::getName() const { 
    return (this->name_);
}

int Form::getGradeSign() const {
    return (this->gradeSign_);
}

int Form::getGradeExecute() const {
    return (this->gradeExecute_);
}

bool Form::getIsSigned() const {
    return (this->isSigned_);
}

void Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= getGradeSign()) {
        this->isSigned_ = true;
    } else {
        throw Form::GradeTooLowException();
    }
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

std::ostream &operator<<(std::ostream &out, Form const &form) {
    out << "Form Name: " << form.getName() << std::endl
    << "Grade to sign: " << form.getGradeSign() << std::endl
    << "Grade to execute: " << form.getGradeExecute() << std::endl
    << "Is signed: " << (form.getIsSigned() ? "yes" : "no") << std::endl;
    return out;
}