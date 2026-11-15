#include <iostream>
#include <stdexcept>
#include <cstdint>
#include "ratexpr/fraction.hpp"


int main() {
    ratexpr::Fraction tik(6, -8);
    ratexpr::Fraction tok(10, 4);
    std::cout << tik << ", " << tok << "\n";

    ratexpr::Fraction pov(1, 2);
    ratexpr::Fraction bot(1, 3);
    std::cout << (pov + bot) << ", " << (pov - bot) << ", " << (pov * bot) << ", " << (pov / bot) << "\n";

    std::uint32_t top = 2;
    std::cout << (pov + top) << ", " << (top + pov) << "\n";
    std::cout << (pov - top) << ", " << (top - pov) << "\n";
    std::cout << (pov / top) << ", " << (top / pov) << "\n";

    ratexpr::Fraction acc = 0;
    acc += pov;
    acc += bot;
    acc *= 6u;
    std::cout << acc << "\n";

    try { 
        ratexpr::Fraction loh1(1, 0); 
    } catch (...) { 
        std::cout << "std::invalid_argument\n"; 
    }

    try { 
        ratexpr::Fraction loh2 = pov / 0u; 
    } catch (...) { 
        std::cout << "std::invalid_argument\n"; 
    }
}