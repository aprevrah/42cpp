#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

AForm::AForm(std::string const name, int gradeSign, int gradeExecute)
    : name_(name), gradeSign_(gradeSign), gradeExecute_(gradeExecute), isSigned_(false) {
    if (gradeSign < 1 || gradeExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeSign > 150 || gradeExecute > 150) {
        throw GradeTooLowException();
    }
}

AForm::AForm(AForm const &other)
    : name_(other.name_), gradeSign_(other.gradeSign_), gradeExecute_(other.gradeExecute_), isSigned_(other.isSigned_) {}

AForm &AForm::operator=(AForm const &rhs) {
    if (this != &rhs) {
        this->isSigned_ = rhs.isSigned_;
    }
    return (*this);
}

AForm::~AForm() {}

std::string const &AForm::getName() const { 
    return (this->name_);
}

int AForm::getGradeSign() const {
    return (this->gradeSign_);
}

int AForm::getGradeExecute() const {
    return (this->gradeExecute_);
}

bool AForm::getIsSigned() const {
    return (this->isSigned_);
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= getGradeSign()) {
        this->isSigned_ = true;
    } else {
        throw AForm::GradeTooLowException();
    }
}

void AForm::execute(const Bureaucrat &executor) const {
    if (!getIsSigned()) {
        std::cerr << getName() << " could not be executed because it has not been signed." << std::endl;
        return;
    }
    if (executor.getGrade() > getGradeExecute()) {
        throw AForm::GradeTooLowException();
    }
    this->executeAction(executor);
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

std::ostream &operator<<(std::ostream &out, AForm const &form) {
    out << "Form Name: " << form.getName() << std::endl
    << "Grade to sign: " << form.getGradeSign() << std::endl
    << "Grade to execute: " << form.getGradeExecute() << std::endl
    << "Is signed: " << (form.getIsSigned() ? "yes" : "no") << std::endl;
    return out;
}