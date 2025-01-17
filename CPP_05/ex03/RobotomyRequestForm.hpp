#pragma once
#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();

    void executeAction(const Bureaucrat &executor) const;

private:
    std::string target_;
};
