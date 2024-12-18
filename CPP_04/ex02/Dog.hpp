#pragma once
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain* brain;
    protected:
        std::string type;
    public:
        Dog(const std::string& type);
        Dog();
        Dog(const Dog& other);
        ~Dog();
        Dog& operator=(const Dog& rhs);

        void makeSound() const;
        Brain* getBrain();
};