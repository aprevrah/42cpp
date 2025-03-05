#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data;
    data.s = "Test string 1212";
    data.n = 22;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized pointer: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized data: " << deserializedData->s << ", " << deserializedData->n << std::endl;

    return 0;
}