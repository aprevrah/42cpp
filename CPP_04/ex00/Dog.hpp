#pragma once
#include <string>
#include "Animal.hpp"

class Dog : public Animal {
    protected:
        std::string type;
    public:
        Dog(const std::string& type);
        Dog();
        Dog(const Dog& other);
        ~Dog();
        Dog& operator=(const Dog& rhs);

        void makeSound() const;
};