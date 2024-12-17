#pragma once
#include <string>
class Animal {
    protected:
        std::string type;
    public:
        Animal(const std::string& type);
        Animal();
        Animal(const Animal& other);
        ~Animal();
        Animal& operator=(const Animal& rhs);

        std::string getType() const;
        virtual void makeSound() const;
};