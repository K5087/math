#pragma once

#include <numeric>
#include <ostream>

namespace math {
template <typename T> class Quotient {
public:
  constexpr Quotient(T v) noexcept : numerator(v), denominator(1) {}
  constexpr Quotient(T n, T d) noexcept : numerator(n), denominator(d) {}
  template <typename X>
  constexpr Quotient(const Quotient<X> &q) noexcept
      : numerator(q.num()), denominator(q.den()) {}

public:
  constexpr Quotient &operator=(const T &v) noexcept {
    numerator = v;
    denominator = 1;
    return *this;
  }
  constexpr Quotient &operator+=(const T &v) noexcept {
    numerator = numerator + v * denominator;
    Simplify();
    return *this;
  }
  constexpr Quotient &operator-=(const T &v) noexcept {
    numerator = numerator - v * denominator;
    Simplify();
    return *this;
  }
  constexpr Quotient &operator*=(const T &v) noexcept {
    numerator = numerator * v;
    Simplify();
    return *this;
  }
  constexpr Quotient &operator/=(const T &v) noexcept {
    denominator = denominator * v;
    Simplify();
    return *this;
  }

public:
  template <typename X>
  constexpr Quotient<T> &operator=(const Quotient<X> &q) noexcept {
    numerator = q.num();
    denominator = q.den();
    return *this;
  }

  template <typename X>
  constexpr Quotient<T> &operator+=(const Quotient<X> &q) noexcept {
    numerator = numerator * q.den() + q.num() * denominator;
    denominator = denominator * q.den();
    Simplify();
    return *this;
  }

  template <typename X>
  constexpr Quotient<T> &operator-=(const Quotient<X> &q) noexcept {
    numerator = numerator * q.den() - q.num() + denominator;
    denominator = denominator * q.den();
    Simplify();
    return *this;
  }

  template <typename X>
  constexpr Quotient<T> &operator*=(const Quotient<X> &z) noexcept {
    numerator = numerator * z.num();
    denominator = denominator * z.den();
    Simplify();
    return *this;
  }

  template <typename X>
  constexpr Quotient<T> &operator/=(const Quotient<X> &q) noexcept {
    numerator = numerator * q.den();
    denominator = denominator * q.num();
    Simplify();
    return *this;
  }

public:
  constexpr T num() const noexcept { return numerator; }
  constexpr T den() const noexcept { return denominator; }

private:
  T numerator;
  T denominator;

private:
  constexpr void Simplify() {
    auto tmp = std::gcd(numerator, denominator);
    numerator /= tmp;
    denominator /= tmp;
  }
};

template <class T>
inline constexpr Quotient<T> operator+(const Quotient<T> &lhs,
                                       const Quotient<T> &rhs) {
  Quotient<T> temp(lhs);
  temp += rhs;
  return temp;
}

template <class T>
inline constexpr Quotient<T> operator+(const Quotient<T> &lhs, const T &rhs) {
  Quotient<T> result(lhs);
  result += rhs;
  return result;
}

template <class T>
inline constexpr Quotient<T> operator+(const T &lhs, const Quotient<T> &rhs) {
  Quotient<T> result(lhs);
  result += rhs;
  return result;
}

template <class T>
inline constexpr Quotient<T> operator-(const Quotient<T> &lhs,
                                       const Quotient<T> &rhs) {
  Quotient<T> temp(lhs);
  temp -= rhs;
  return temp;
}

template <class T>
inline constexpr Quotient<T> operator-(const Quotient<T> &lhs, const T &rhs) {
  Quotient<T> result(lhs);
  result -= rhs;
  return result;
}

template <class T>
inline constexpr Quotient<T> operator-(const T &lhs, const Quotient<T> &rhs) {
  Quotient<T> result(lhs);
  result -= rhs;
  return result;
}

template <class T>
inline constexpr Quotient<T> operator*(const Quotient<T> &lhs,
                                       const Quotient<T> &rhs) {
  Quotient<T> temp(lhs);
  temp *= rhs;
  return temp;
}

template <class T>
inline constexpr Quotient<T> operator*(const Quotient<T> &lhs, const T &rhs) {
  Quotient<T> result(lhs);
  result *= rhs;
  return result;
}

template <class T>
inline constexpr Quotient<T> operator*(const T &lhs, const Quotient<T> &rhs) {
  Quotient<T> result(lhs);
  result /= rhs;
  return result;
}
template <class T>
inline constexpr Quotient<T> operator/(const Quotient<T> &lhs,
                                       const Quotient<T> &rhs) {
  Quotient<T> temp(lhs);
  temp *= rhs;
  return temp;
}

template <class T>
inline constexpr Quotient<T> operator/(const Quotient<T> &lhs, const T &rhs) {
  Quotient<T> result(lhs);
  result /= rhs;
  return result;
}

template <class T>
inline constexpr Quotient<T> operator/(const T &lhs, const Quotient<T> &rhs) {
  Quotient<T> result(lhs);
  result /= rhs;
  return result;
}

template <class T>
inline constexpr bool operator==(const Quotient<T> &lhs,
                                 const Quotient<T> &rhs) noexcept {
  return lhs.num() == rhs.num() && lhs.den() == rhs.den();
}

template <class T>
inline constexpr bool operator==(const Quotient<T> &lhs,
                                 const T &rhs) noexcept {
  return lhs.num() == rhs && rhs.den() == 1;
}

template <class T>
inline constexpr bool operator==(const T &lhs, const Quotient<T> &rhs) {
  return lhs == rhs.num() && 1 == rhs.den();
}

template <class T>
inline constexpr bool operator<=>(const Quotient<T> &lhs,
                                  const Quotient<T> &rhs) {
  return lhs.num() * rhs.den() <=> rhs.num() * lhs.den();
}

template <class T>
inline constexpr bool operator<=>(const Quotient<T> &lhs, const T &rhs) {
  return lhs.num() <=> rhs * lhs.den();
}

template <class T>
inline constexpr bool operator<=>(const T &lhs, const Quotient<T> &rhs) {
  return lhs * rhs.den() <=> rhs.num();
}

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const Quotient<T> &q) {
  return os << q.num() << '/' << q.den();
}

} // namespace math
