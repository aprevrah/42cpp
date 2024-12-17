#pragma once
#include <string>
class WrongAnimal {
    protected:
        std::string type;
    public:
        WrongAnimal(const std::string& type);
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        ~WrongAnimal();
        WrongAnimal& operator=(const WrongAnimal& rhs);

        std::string getType() const;
        void makeSound() const;
};