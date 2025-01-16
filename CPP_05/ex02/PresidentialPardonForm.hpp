#pragma once
#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();

    void execute(const Bureaucrat &executor) const;

private:
    std::string target_;
};
