#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main() {
    {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 10);
        Bureaucrat ronald("Ronald", 11);
        Form boringForm("Boooring", 10, 1);
        Form otherBoringForm(boringForm);
        ronald.signForm(otherBoringForm);
        std::cout << boringForm;
        bob.signForm(boringForm);
        alice.signForm(otherBoringForm);
        std::cout << boringForm;
        Form defaultForm;
        std::cout << defaultForm;
    }

    return (0);
}