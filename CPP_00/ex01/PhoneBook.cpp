
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

int PhoneBook::getString(const std::string& prompt, std::string& str)
{
    bool isValid = false;
    while (!isValid)
    {
        isValid = true;
        std::cout << prompt;
        if (!std::getline(std::cin, str))
            return 1;
        for (size_t i = 0; i < str.size(); ++i) {
        if (!(std::isalnum(str[i])))
            isValid = false;
        }
        if (!isValid)
            std::cout << "Invalid, try again..." << std::endl;
    }
    return 0;
}

int PhoneBook::addContact() {
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    if (getString("Enter First Name: ", firstName))
        return 1;
    if (getString("Enter Last Name: ", lastName))
        return 1;
    if (getString("Enter Nickname: ", nickname))
        return 1;
    bool isValid = false;
    while (!isValid)
    {
        std::cout << "Enter Phone Number: ";
        if (!std::getline(std::cin, phoneNumber))
            return 1;
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
    if (contactCount >= MAX_CONTACTS * 2)
        contactCount = MAX_CONTACTS;

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
            std::cout << "Invalid, try again: ";

        if (!(std::cin >> index)) {
            if (std::cin.eof())
                return 1;
            index = -2;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    contacts[index].displayDetails();
    return 0;
}