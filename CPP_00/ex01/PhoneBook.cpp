
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() 
{
    contactCount = 0;
}

bool PhoneBook::isValidPhoneNumber(const std::string& phoneNumber)
{
    if (phoneNumber.empty())
        return false;

    for (size_t i = 0; i < phoneNumber.size(); ++i) {
        if (std::isalpha(phoneNumber[i]))
            return false;
    }
    return true;
}

int PhoneBook::addContact() {
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << "Enter First Name: ";
    if (!std::getline(std::cin, firstName))
        return 1;
    std::cout << "Enter Last Name: ";
    if (!std::getline(std::cin, lastName))
        return 1;
    std::cout << "Enter Nickname: ";
    if (!std::getline(std::cin, nickname))
        return 1;
    bool isValid = false;
    while (!isValid)
    {
        std::cout << "Enter Phone Number: ";
        if (!std::getline(std::cin, phoneNumber))
            break;
        if (!(isValid = isValidPhoneNumber(phoneNumber)))
            std::cout << "Invalid phone number try again..." << std::endl;
    }
    std::cout << "Enter Darkest Secret: ";
    if (!std::getline(std::cin, darkestSecret))
        return 1;

    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
        std::cout << "Error: All fields must be filled." << std::endl;
        return 0;
    }

    int index = contactCount % MAX_CONTACTS;
    contacts[index].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    contactCount++;

    std::cout << "Contact added successfully!" << std::endl;
    return 0;
}

int PhoneBook::searchContact() const {
    if (contactCount == 0) {
        std::cout << "😔 Phonebook is empty." << std::endl;
        return 0;
    }

    std::cout << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nickname" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < MAX_CONTACTS && i < contactCount; ++i) {
        contacts[i].displaySummary(i);
    }

    int index = -1;
    while (index < 0 || index >= MAX_CONTACTS || index >= contactCount) {
        if (index == -1)
            std::cout << "Enter the index of the contact to display: ";
        else 
            std::cout << "Invalid, try a number between 0 and " << contactCount - 1 << ": ";

        if (!(std::cin >> index))
            index = -2;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    contacts[index].displayDetails();
    return 0;
}