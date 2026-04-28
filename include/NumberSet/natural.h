#pragma once
#include <concepts>
#include <ostream>

namespace math {

template <typename T>
concept unsigned_integral = std::is_integral_v<T> && std::is_unsigned_v<T>;

template <std::unsigned_integral T> class Natural {
public:
  constexpr Natural(T v) noexcept : value_(v) {}
  template <typename X>
  constexpr Natural(const Natural<X> &v) noexcept : value_(v.value()) {}

public:
  constexpr Natural<T> &operator=(const T &v) {
    value_ = v;
    return *this;
  }
  constexpr Natural<T> &operator+=(const T &v) noexcept {
    value_ += v;
    return *this;
  }
  constexpr Natural<T> &operator*=(const T &v) noexcept {
    value_ *= v;
    return *this;
  }

public:
  template <typename X>
  constexpr Natural<T> &operator=(const Natural<X> &v) noexcept {
    value_ = v.value();
    return *this;
  }

  template <typename X>
  constexpr Natural<T> &operator+=(const Natural<X> &others) noexcept {
    value_ += others.value();
    return *this;
  }

  template <typename X>
  constexpr Natural<T> &operator*=(const Natural<X> &others) noexcept {
    value_ *= others.value();
    return *this;
  }

public:
  constexpr T value() const noexcept { return value_; }

private:
  T value_ = {};
};

template <class T>
inline constexpr Natural<T> operator+(const Natural<T> &lhs,
                                      const Natural<T> &rhs) {
  Natural<T> temp(lhs);
  temp += rhs;
  return temp;
}

template <class T>
inline constexpr Natural<T> operator+(const Natural<T> &lhs, const T &rhs) {
  Natural<T> result(lhs);
  result += rhs;
  return result;
}

template <class T>
inline constexpr Natural<T> operator+(const T &lhs, const Natural<T> &rhs) {
  Natural<T> result(lhs);
  result += rhs;
  return result;
}

template <class T>
inline constexpr Natural<T> operator*(const Natural<T> &lhs,
                                      const Natural<T> &rhs) {
  Natural<T> temp(lhs);
  temp *= rhs;
  return temp;
}

template <class T>
inline constexpr Natural<T> operator*(const Natural<T> &lhs, const T &rhs) {
  Natural<T> result(lhs);
  result *= rhs;
  return result;
}

template <class T>
inline constexpr Natural<T> operator*(const T &lhs, const Natural<T> &rhs) {
  Natural<T> result(lhs);
  result *= rhs;
  return result;
}
template <class T>
inline constexpr bool operator==(const Natural<T> &lhs,
                                 const Natural<T> &rhs) noexcept {
  return lhs.value() == rhs.value();
}
template <class T>
inline constexpr bool operator==(const Natural<T> &lhs, const T &rhs) noexcept {
  return lhs.value() == rhs;
}
template <class T>
inline constexpr bool operator==(const T &lhs, const Natural<T> &rhs) {
  return lhs == rhs.value();
}

template <class T>
inline constexpr bool operator<=>(const Natural<T> &lhs,
                                  const Natural<T> &rhs) {
  return lhs.value() <=> rhs.value();
}
template <class T>
inline constexpr bool operator<=>(const Natural<T> &lhs, const T &rhs) {
  return lhs.value() <=> rhs;
}
template <class T>
inline constexpr bool operator<=>(const T &lhs, const Natural<T> &rhs) {
  return lhs <=> rhs.value();
}
template <class T>
inline std::ostream &operator<<(std::ostream &os, const Natural<T> &n) {
  return os << n.value();
}

} // namespace math
