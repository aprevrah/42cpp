#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* createShrubberyCreationForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomyRequestForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardonForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
    typedef AForm* (*FormCreator)(const std::string &target);
    struct FormType {
        std::string name;
        FormCreator creator;
    };

    FormType formTypes[] = {
        {"shrubbery creation", createShrubberyCreationForm},
        {"robotomy request", createRobotomyRequestForm},
        {"presidential pardon", createPresidentialPardonForm}
    };

    for (int i = 0; i < 3; ++i) {
        if (formTypes[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return formTypes[i].creator(target);
        }
    }

    std::cerr << "Error: Form name \"" << formName << "\" does not exist." << std::endl;
    return NULL;
}