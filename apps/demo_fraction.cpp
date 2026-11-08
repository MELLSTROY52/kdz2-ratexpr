#include <iostream>
#include <stdexcept>
#include <cstdint>
#include "fraction.hpp"

using namespace ratexpr;

int main() {
    std::cout << Fraction(6, -8) << ", " << Fraction(10, 4) << "\n";

    Fraction half(1, 2);
    Fraction third(1, 3);
    std::cout << (half + third) << ", " << (half - third) << ", " << (half * third) << ", " << (half / third) << "\n";

    std::uint32_t two = 2;
    std::cout << (half + two) << " и " << (two + half) << "\n";
    std::cout << (half - two) << " и " << (two - half) << "\n";
    std::cout << (half / two) << " и " << (two / half) << "\n";

    Fraction acc = 0;
    acc += half;
    acc += third;
    acc *= 6u;
    std::cout << acc << "\n";

    try {
        Fraction bad(1, 0);
    } catch (const std::invalid_argument& e) {
        std::cout << "std::invalid_argument\n";
    }

    try {
        Fraction res = half / 0u;
    } catch (const std::invalid_argument& e) {
        std::cout << "std::invalid_argument\n";
    }

    return 0;
}