#pragma once
#include <concepts>
#include <ostream>

namespace math {
template <std::integral T> class Zahlen {
public:
  constexpr Zahlen(T v) noexcept : value_(v) {}
  template <typename X>
  constexpr Zahlen(const Zahlen<X> &v) noexcept : value_(v.value()) {}

public:
  constexpr Zahlen &operator=(const T &v) noexcept {
    value_ = v;
    return *this;
  }
  constexpr Zahlen &operator+=(const T &v) noexcept {
    value_ += v;
    return *this;
  }
  constexpr Zahlen &operator-=(const T &v) noexcept {
    value_ -= v;
    return *this;
  }
  constexpr Zahlen &operator*=(const T &v) noexcept {
    value_ *= v;
    return *this;
  }

public:
  template <typename X>
  constexpr Zahlen<T> &operator=(const Zahlen<X> &z) noexcept {
    value_ = z.value();
    return *this;
  }

  template <typename X>
  constexpr Zahlen<T> &operator+=(const Zahlen<X> &z) noexcept {
    value_ += z.value();
    return *this;
  }
  template <typename X>
  constexpr Zahlen<T> &operator-=(const Zahlen<X> &z) noexcept {
    value_ -= z.value();
    return *this;
  }

  template <typename X>
  constexpr Zahlen<T> &operator*=(const Zahlen<X> &z) noexcept {
    value_ *= z.value();
    return *this;
  }

public:
  constexpr T value() const noexcept { return value_; }

private:
  T value_ = {};
};
template <class T>
inline constexpr Zahlen<T> operator+(const Zahlen<T> &lhs,
                                     const Zahlen<T> &rhs) {
  Zahlen<T> temp(lhs);
  temp += rhs;
  return temp;
}

template <class T>
inline constexpr Zahlen<T> operator+(const Zahlen<T> &lhs, const T &rhs) {
  Zahlen<T> result(lhs);
  result += rhs;
  return result;
}

template <class T>
inline constexpr Zahlen<T> operator+(const T &lhs, const Zahlen<T> &rhs) {
  Zahlen<T> result(lhs);
  result += rhs;
  return result;
}

template <class T>
inline constexpr Zahlen<T> operator-(const Zahlen<T> &lhs,
                                     const Zahlen<T> &rhs) {
  Zahlen<T> temp(lhs);
  temp -= rhs;
  return temp;
}

template <class T>
inline constexpr Zahlen<T> operator-(const Zahlen<T> &lhs, const T &rhs) {
  Zahlen<T> result(lhs);
  result -= rhs;
  return result;
}

template <class T>
inline constexpr Zahlen<T> operator-(const T &lhs, const Zahlen<T> &rhs) {
  Zahlen<T> result(lhs);
  result -= rhs;
  return result;
}

template <class T>
inline constexpr Zahlen<T> operator*(const Zahlen<T> &lhs,
                                     const Zahlen<T> &rhs) {
  Zahlen<T> temp(lhs);
  temp *= rhs;
  return temp;
}

template <class T>
inline constexpr Zahlen<T> operator*(const Zahlen<T> &lhs, const T &rhs) {
  Zahlen<T> result(lhs);
  result *= rhs;
  return result;
}

template <class T>
inline constexpr Zahlen<T> operator*(const T &lhs, const Zahlen<T> &rhs) {
  Zahlen<T> result(lhs);
  result *= rhs;
  return result;
}

template <class T>
inline constexpr bool operator==(const Zahlen<T> &lhs,
                                 const Zahlen<T> &rhs) noexcept {
  return lhs.value() == rhs.value();
}

template <class T>
inline constexpr bool operator==(const Zahlen<T> &lhs, const T &rhs) noexcept {
  return lhs.value() == rhs;
}

template <class T>
inline constexpr bool operator==(const T &lhs, const Zahlen<T> &rhs) {
  return lhs == rhs.value();
}

template <class T>
inline constexpr bool operator<=>(const Zahlen<T> &lhs, const Zahlen<T> &rhs) {
  return lhs.value() <=> rhs.value();
}

template <class T>
inline constexpr bool operator<=>(const Zahlen<T> &lhs, const T &rhs) {
  return lhs.value() <=> rhs;
}

template <class T>
inline constexpr bool operator<=>(const T &lhs, const Zahlen<T> &rhs) {
  return lhs <=> rhs.value();
}

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const Zahlen<T> &z) {
  return os << z.value();
}
} // namespace math
