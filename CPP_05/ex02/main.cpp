#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 150);
        Bureaucrat ronald("Ronald", 11);
        
        RobotomyRequestForm rRForm("Ronald");
        std::cout << rRForm;
        ronald.executeForm(rRForm);
        bob.signForm(rRForm);
        ronald.signForm(rRForm);
        ronald.executeForm(rRForm);

        ShrubberyCreationForm sCForm("Test");
        ronald.signForm(sCForm);
        ronald.executeForm(sCForm);

        PresidentialPardonForm pPForm("Ronald");
        ronald.signForm(pPForm);
        ronald.executeForm(pPForm);
        alice.executeForm(pPForm);
    }
    return (0);
}