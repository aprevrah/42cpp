#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <exception>
#include <iostream>

int main() {
    {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 10);
        Bureaucrat ronald("Ronald", 11);
        ShrubberyCreationForm sCForm("test");
        RobotomyRequestForm rRForm("ron");
        ronald.signForm(sCForm);
        std::cout << sCForm;
        sCForm.execute(ronald);
        bob.signForm(rRForm);
        std::cout << rRForm;
        rRForm.execute(ronald);
    }
    return (0);
}