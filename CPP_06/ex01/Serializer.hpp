#pragma once
#include <string>
#include <iostream>
#include <stdint.h>

struct Data
{
    std::string s;
    int n;
};

class Serializer
{
    private:
    Serializer();
    Serializer(Serializer const &other);
    Serializer &operator=(Serializer const &rhs);
    ~Serializer();

    public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};