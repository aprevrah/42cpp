#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main() {
    {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 10);
        Bureaucrat ronald("Ronald", 11);
        ShrubberyCreationForm sCForm("test");
        ronald.signForm(sCForm);
        std::cout << sCForm;
        sCForm.execute(ronald);
    }
    return (0);
}