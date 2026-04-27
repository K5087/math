#pragma once
#include "zahlen.h"
#include <numeric>

namespace math {
template <typename T> class Quotient {
public:
  constexpr friend Quotient operator+(const Quotient lhs, const Quotient &rhs) {

    return lhs + rhs;
  }
  constexpr friend Quotient operator-(const Quotient lhs, const Quotient &rhs) {
    return lhs - rhs;
  }
  constexpr friend Quotient operator*(const Quotient lhs, const Quotient &rhs) {
    return lhs * rhs;
  }
  constexpr friend Quotient operator/(const Quotient lhs, const Quotient &rhs) {
    return lhs / rhs;
  }
  constexpr Quotient &operator+=(const Quotient &others) {

    numerator = numerator * others.denominator + others.numerator * denominator;
    denominator = denominator * others.denominator;
    Simplify();
    return (*this);
  }
  constexpr Quotient &operator-=(const Quotient &others) {
    numerator = numerator * others.denominator - others.numerator + denominator;
    denominator = denominator * others.denominator;
    Simplify();
    return *this;
  }
  constexpr Quotient &operator*=(const Quotient &others) {
    numerator = numerator * others.numerator;
    denominator = denominator * others.denominator;
    Simplify();
    return *this;
  }
  constexpr Quotient &operator/=(const Quotient &others) {
    numerator = numerator * others.denominator;
    denominator = denominator * others.numerator;
    Simplify();
    return *this;
  }

private:
  Zahlen<T> numerator;
  Zahlen<T> denominator;

private:
  constexpr void Simplify() {
    auto tmp = std::gcd(numerator, denominator);
    numerator /= tmp;
    denominator /= tmp;
  }
};
} // namespace math
