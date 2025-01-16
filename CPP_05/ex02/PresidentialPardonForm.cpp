#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon", 25, 5), target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), target_(other.target_) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        target_ = other.target_;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (!getIsSigned()) {
        std::cerr << getName() << " could not be executed because it has not been signed." << std::endl;
        return;
    }
    if (executor.getGrade() > getGradeExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}