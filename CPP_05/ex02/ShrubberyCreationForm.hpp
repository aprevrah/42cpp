#pragma once
#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();

    void execute(const Bureaucrat &executor) const;

private:
    std::string target_;
};
