#include "Serializer.hpp"
#include <iostream>

int main() {
    Data originalData = {1, "Test Data", 42.0f};

    // Serialize the Data object
    unsigned long raw = Serializer::serialize(&originalData);

    // Deserialize the unsigned long back to a Data pointer
    Data* deserializedData = Serializer::deserialize(raw);

    // Check if the deserialized pointer is equal to the original pointer
    if (deserializedData == &originalData) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "Data ID: " << deserializedData->id << std::endl;
        std::cout << "Data Name: " << deserializedData->name << std::endl;
        std::cout << "Data Value: " << deserializedData->value << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }

    return 0;
}
