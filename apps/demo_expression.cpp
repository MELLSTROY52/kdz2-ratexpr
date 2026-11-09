#include <iostream>
#include <memory>
#include "ratexpr/expression.hpp"
#include "ratexpr/fraction.hpp"

using namespace ratexpr;

int main() {
    auto e1 = std::make_unique<Mul>(
        std::make_unique<Add>(
            std::make_unique<Const>(Fraction(1, 2)),
            std::make_unique<Const>(Fraction(1, 3))
        ),
        std::make_unique<Sub>(
            std::make_unique<Const>(Fraction(3)),
            std::make_unique<Const>(Fraction(1, 4))
        )
    );
    std::cout << *e1 << " = " << e1->evaluate() << "\n";

    auto e2 = std::make_unique<Negative>(
        std::make_unique<Div>(
            std::make_unique<Const>(Fraction(2)),
            std::make_unique<Const>(Fraction(3))
        )
    );
    std::cout << *e2 << " = " << e2->evaluate() << "\n";
}
