#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <limits>

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {
			std::cout << std::endl;
            break;
		}
        if (command == "ADD") {
            if (phoneBook.addContact()) {
                std::cout << std::endl;
                return 0;
            }
        } else if (command == "SEARCH") {
            if (phoneBook.searchContact()) {
                std::cout << std::endl;
                return 0;
            }
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Unknown command. Please try again." << std::endl;
        }
    }
    return 0;
}