#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
private:
    Contact contacts[MAX_CONTACTS];
    int contactCount;
public:
    PhoneBook();

    void addContact();

    void searchContact() const;
};