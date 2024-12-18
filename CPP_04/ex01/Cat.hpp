#pragma once
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain* brain;
    protected:
        std::string type;
    public:
        Cat(const std::string& type);
        Cat();
        Cat(const Cat& other);
        ~Cat();
        Cat& operator=(const Cat& rhs);

        void makeSound() const;
};