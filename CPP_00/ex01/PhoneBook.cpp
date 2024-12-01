
#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() 
{
}

void PhoneBook::addContact() {
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkestSecret);

    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
        std::cout << "Error: All fields must be filled." << std::endl;
        return;
    }

    int index = contactCount % MAX_CONTACTS;
    contacts[index].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    contactCount++;

    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContact() const {
    if (contactCount == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nickname" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < MAX_CONTACTS && i < contactCount; ++i) {
        contacts[i].displaySummary(i);
    }

    std::cout << "Enter the index of the contact to display: ";
    int index;
    std::cin >> index;
    std::cin.ignore(); // Ignore leftover newline

    if (index < 0 || index >= MAX_CONTACTS || index >= contactCount) {
        std::cout << "Error: Invalid index." << std::endl;
    } else {
        contacts[index].displayDetails();
    }
}