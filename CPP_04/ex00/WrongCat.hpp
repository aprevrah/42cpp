#pragma once
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    protected:
        std::string type;
    public:
        WrongCat(const std::string& type);
        WrongCat();
        WrongCat(const WrongCat& other);
        ~WrongCat();
        WrongCat& operator=(const WrongCat& rhs);

        void makeSound() const;
};