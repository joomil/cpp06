#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>
#include <cctype>
#include <cstdlib> // for strtod
#include <cmath>   // for isnan, isinf

void ScalarConverter::convert(const std::string& input) {
    char* end;
    double value = std::strtod(input.c_str(), &end);

    if (*end != '\0') {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    // Convert to char
    if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max() || std::isnan(value)) {
        std::cout << "char: impossible\n";
    } else if (std::isprint(static_cast<char>(value))) {
        std::cout << "char: '" << static_cast<char>(value) << "'\n";
    } else {
        std::cout << "char: Non displayable\n";
    }

    // Convert to int
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value)) {
        std::cout << "int: impossible\n";
    } else {
        std::cout << "int: " << static_cast<int>(value) << "\n";
    }

    // Convert to float
    if (std::isnan(value)) {
        std::cout << "float: nanf\n";
    } else if (std::isinf(value)) {
        std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << "\n";
    } else {
        std::cout << "float: " << static_cast<float>(value) << "f\n";
    }

    // Convert to double
    if (std::isnan(value)) {
        std::cout << "double: nan\n";
    } else if (std::isinf(value)) {
        std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << "\n";
    } else {
        std::cout << "double: " << value << "\n";
    }
}
