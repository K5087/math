#pragma once
#include "ostream"
#include "zahlen.h"
#include <numeric>

namespace math {
template <typename T> class Quotient {
public:
  Quotient(T n, T d) noexcept : numerator(n), denominator(d) {}

public:
  constexpr friend Quotient operator+(const Quotient lhs,
                                      const Quotient &rhs) noexcept {
    lhs += rhs;
    return lhs;
  }
  constexpr friend Quotient operator-(const Quotient lhs,
                                      const Quotient &rhs) noexcept {
    lhs -= rhs;
    return lhs;
  }
  constexpr friend Quotient operator*(const Quotient lhs,
                                      const Quotient &rhs) noexcept {
    lhs *= rhs;
    return lhs;
  }
  constexpr friend Quotient operator/(const Quotient lhs,
                                      const Quotient &rhs) noexcept {
    lhs /= rhs;
    return lhs;
  }
  constexpr Quotient &operator+=(const Quotient &others) noexcept {

    numerator = numerator * others.denominator + others.numerator * denominator;
    denominator = denominator * others.denominator;
    Simplify();
    return (*this);
  }
  constexpr Quotient &operator-=(const Quotient &others) noexcept {
    numerator = numerator * others.denominator - others.numerator + denominator;
    denominator = denominator * others.denominator;
    Simplify();
    return *this;
  }
  constexpr Quotient &operator*=(const Quotient &others) noexcept {
    numerator = numerator * others.numerator;
    denominator = denominator * others.denominator;
    Simplify();
    return *this;
  }
  constexpr Quotient &operator/=(const Quotient &others) noexcept {
    numerator = numerator * others.denominator;
    denominator = denominator * others.numerator;
    Simplify();
    return *this;
  }

public:
  friend std::ostream &operator<<(std::ostream &o, const Quotient &q) {
    return o << q.numerator << '/' << q.denominator;
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
