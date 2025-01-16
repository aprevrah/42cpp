#include "ShrubberyCreationForm.hpp"
#include <fstream>

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

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (!getIsSigned()) {
        std::cerr << getName() << " could not be executed because it has not been signed." << std::endl;
        return;
    }
    if (executor.getGrade() > getGradeExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::string outputFilename = target_ + "_shrubbery";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create output file " << outputFilename << std::endl;
    }
    outputFile << "Tree: <|>";
    outputFile.close();
}