#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137), target_("Default Target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation", 145, 137), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target_(other.target_) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        target_ = other.target_;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction(const Bureaucrat &executor) const {

    std::string outputFilename = target_ + "_shrubbery";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create output file " << outputFilename << std::endl;
    }
    outputFile << 
    "     _______\n"
    "  __(      ~)__\n"
    " (   ( )      ~)\n"
    "(  (      )     )\n"
    " \\  _-     -_  /\n"
    "   ~  \\\\ //  ~\n"
    "_- -   | | _- _\n"
    "  _ -  | |   -_\n"
    "      // \\\\\n"
    "planted by " << executor.getName();
    outputFile.close();
}