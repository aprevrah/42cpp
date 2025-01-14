#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>


RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target_(other.target_) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        target_ = other.target_;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (!getIsSigned()) {
        throw AForm::GradeTooLowException();
    }
    if (executor.getGrade() > getGradeExecute()) {
        throw AForm::GradeTooLowException();
    }
    srand(time(0));
    if (rand() % 2) {
        std::cout << target_ << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << target_ << "'s robotomy has failed" << std::endl;
    }
}