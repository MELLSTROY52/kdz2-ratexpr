
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <fraction.hpp>
#include <cstdlib>

namespace ratexpr {
        std::int64_t Fraction::gcd(std::int64_t a, std::int64_t b) const {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0) {
            std::int64_t temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void Fraction::Stablelool() {
        if (den < 0) {
            num = -num;
            den = -den;
        }
        std::int64_t divisor = gcd(num, den);
        if (divisor > 1) {
            num /= divisor;
            den /= divisor;
        }
    }
    Fraction::Fraction() : num(0), den(1) {}

    Fraction::Fraction(std::int64_t numerator, std::int64_t denominator) : num(numerator), den(denominator) {
        if (den == 0) {
            throw std::invalid_argument("Нелья делить на 0");
        }
        Stablelool();
    }

    Fraction& Fraction::operator +=(const Fraction& o) {
        num = num * o.den + den * o.num;
        den = den * o.den;
        Stablelool();
        return *this;
    }

    Fraction& Fraction::operator -=(const Fraction& o) {
        num = num * o.den - den * o.num;
        den = den * o.den;
        Stablelool();
        return *this;
    }

    Fraction& Fraction::operator *=(const Fraction& o) {
        num *= o.num;
        den *= o.den;
        Stablelool();
        return *this;
    }

    Fraction& Fraction::operator /=(const Fraction& o) {
        if (o.num == 0) {
            throw std::invalid_argument("Нельзя делить на 0");
        }
        num *= o.den;
        den *= o.num;
        Stablelool();
        return *this;
    }

    Fraction& Fraction::operator+=(std::uint32_t k) { return *this += Fraction(k); }

    Fraction& Fraction::operator-=(std::uint32_t k) { return *this -= Fraction(k); }

    Fraction& Fraction::operator*=(std::uint32_t k) { return *this *= Fraction(k); }

    Fraction& Fraction::operator/=(std::uint32_t k) { return *this /= Fraction(k); }

    Fraction operator+(const Fraction& a, const Fraction& b) {
        Fraction gay = a;
        gay += b;
        return gay;
    }

    Fraction operator+(const Fraction& a, std::uint32_t k) {
        Fraction gay = a;
        gay += k;
        return gay;
    }

    Fraction operator+(std::uint32_t k, const Fraction& b) {
        Fraction gay(k);
        gay += b;
        return gay;
    }

    Fraction operator-(const Fraction& a, const Fraction& b) {
        Fraction gay = a;
        gay -= b;
        return gay;
    }

    Fraction operator-(const Fraction& a, std::uint32_t k) {
        Fraction gay = a;
        gay -= k;
        return gay;
    }

    Fraction operator-(std::uint32_t k, const Fraction& b) {
        Fraction gay(k);
        gay -= b;
        return gay;
    }

    Fraction operator*(const Fraction& a, const Fraction& b) {
        Fraction gay = a;
        gay *= b;
        return gay;
    }

    Fraction operator*(const Fraction& a, std::uint32_t k) {
        Fraction gay = a;
        gay *= k;
        return gay;
    }

    Fraction operator*(std::uint32_t k, const Fraction& b) {
        Fraction gay(k);
        gay *= b;
        return gay;
    }

    Fraction operator/(const Fraction& a, const Fraction& b) {
        Fraction gay = a;
        gay /= b;
        return gay;
    }

    Fraction operator/(const Fraction& a, std::uint32_t k) {
        Fraction gay = a;
        gay /= k;
        return gay;
    }

    Fraction operator/(std::uint32_t k, const Fraction& b) {
        Fraction gay(k);
        gay /= b;
        return gay;
    }

    Fraction Fraction::operator-() const {
        return Fraction(-num, den);
    }

    std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        return os << f.num << '/' << f.den;
    }
}