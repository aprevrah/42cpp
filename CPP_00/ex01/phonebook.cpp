#include <iostream>
#include <string>
#include <algorithm>

class Contact {
    private:
    std::string first_name; 
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    public:
    Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret) 
        : first_name(first_name), last_name(last_name), nickname(nickname), phone_number(phone_number), darkest_secret(darkest_secret) {}
    std::string get_first_name() { return first_name; }
    std::string get_last_name() { return last_name; }
    std::string get_nickname() { return nickname; }
    std::string get_phone_number() { return phone_number; }
    std::string get_darkest_secret() { return darkest_secret; }
    
};

class PhoneBook {
    private:

    public:
    PhoneBook() {}

    void add_contact() {
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
        std::cout << "First name: ";
        std::cin >> first_name;
        std::cout << "Last name: ";
        std::cin >> last_name;
        std::cout << "Nickname: ";
        std::cin >> nickname;
        std::cout << "Phone number: ";
        std::cin >> phone_number;
        std::cout << "Darkest secret: ";
        std::cin >> darkest_secret;
        if (first_name.empty() || last_name.empty() || nickname.empty() || phone_number.empty() || darkest_secret.empty()) {
            std::cout << "Error: all fields are required" << std::endl;
            return;
        }
        Contact contact(first_name, last_name, nickname, phone_number, darkest_secret);
    }
    
};

int main() {
    std::string command;
    PhoneBook phone_book;
    while (1) {
            std::cout << "ADD, SEARCH or EXIT: ";
            std::cin >> command;
            if (command == "ADD") {
                phone_book.add_contact();
            }
            else if (command == "SEARCH") {
                std::cout << "SEARCH" << std::endl;
            }
            else if (command == "EXIT") {
                break;
            }
            else {
                std::cout << "Invalid command" << std::endl;
            }
        }
        std::cout << std::endl;
    return 0;
}