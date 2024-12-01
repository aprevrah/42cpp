#pragma once
#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    
    bool isEmpty() const;

    void setContact(const std::string& first, const std::string& last, const std::string& nick,
                    const std::string& phone, const std::string& secret);

    void displaySummary(int index) const;

    void displayDetails() const;

private:
    static std::string truncateField(const std::string& field);
};