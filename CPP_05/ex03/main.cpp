#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 150);
        Bureaucrat ronald("Ronald", 11);
        
        Intern someRandomIntern;
        AForm* rRForm = someRandomIntern.makeForm("robotomy request", "Ronald");
        if (rRForm) {
            std::cout << *rRForm;
            ronald.executeForm(*rRForm);
            bob.signForm(*rRForm);
            ronald.signForm(*rRForm);
            ronald.executeForm(*rRForm);
            delete rRForm;
        }

        AForm* sCForm = someRandomIntern.makeForm("shrubbery creation", "Test");
        if (sCForm) {
            ronald.signForm(*sCForm);
            ronald.executeForm(*sCForm);
            delete sCForm;
        }

        AForm* pPForm = someRandomIntern.makeForm("presidential pardon", "Ronald");
        if (pPForm) {
            ronald.signForm(*pPForm);
            ronald.executeForm(*pPForm);
            alice.executeForm(*pPForm);
            delete pPForm;
        }

        AForm* nAForm = someRandomIntern.makeForm("not a form", "Ronald");
        if (nAForm) {
            delete nAForm; //this should never happen.
        }
    }
    return (0);
}