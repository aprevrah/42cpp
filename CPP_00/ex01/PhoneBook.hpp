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

    int addContact();

    int searchContact() const;
    static bool isValidPhoneNumber(const std::string& phoneNumber);
    static int  getString(const std::string& prompt, std::string& str);
};