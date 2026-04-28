#pragma onc

#include <concepts>
#include <ostream>

namespace math {
template <std::floating_point T> class Real {
public:
  constexpr Real(T v) noexcept : value_(v) {}
  template <typename X>
  constexpr Real(const Real<X> &r) noexcept : value_(r.value()) {}

public:
  constexpr Real<T> &operator+=(const T &r) noexcept {
    value_ += r;
    return *this;
  }

  constexpr Real<T> &operator-=(const T &r) noexcept {
    value_ -= r;
    return *this;
  }

  constexpr Real<T> &operator*=(const T &r) noexcept {
    value_ *= r;
    return *this;
  }

  constexpr Real<T> &operator/=(const T &r) noexcept {
    value_ /= r;
    return *this;
  }

public:
  template <typename X>
  constexpr Real<T> &operator+=(const Real<X> &r) noexcept {

    value_ += r.value();
    return (*this);
  }

  template <typename X>
  constexpr Real<T> &operator-=(const Real<X> &r) noexcept {
    value_ -= r.value();
    return *this;
  }

  template <typename X>
  constexpr Real<T> &operator*=(const Real<X> &r) noexcept {
    value_ *= r.value();
    return *this;
  }

  template <typename X>
  constexpr Real<T> &operator/=(const Real<X> &r) noexcept {
    value_ /= r.value();
    return *this;
  }

public:
  constexpr T value() const noexcept { return value_; }

private:
  T value_ = {};
};

template <class T>
inline constexpr Real<T> operator+(const Real<T> &lhs, const Real<T> &rhs) {
  Real<T> temp(lhs);
  temp += rhs;
  return temp;
}

template <class T>
inline constexpr Real<T> operator+(const Real<T> &lhs, const T &rhs) {
  Real<T> result(lhs);
  result += rhs;
  return result;
}

template <class T>
inline constexpr Real<T> operator+(const T &lhs, const Real<T> &rhs) {
  Real<T> result(lhs);
  result += rhs;
  return result;
}

template <class T>
inline constexpr Real<T> operator-(const Real<T> &lhs, const Real<T> &rhs) {
  Real<T> temp(lhs);
  temp -= rhs;
  return temp;
}

template <class T>
inline constexpr Real<T> operator-(const Real<T> &lhs, const T &rhs) {
  Real<T> result(lhs);
  result -= rhs;
  return result;
}

template <class T>
inline constexpr Real<T> operator-(const T &lhs, const Real<T> &rhs) {
  Real<T> result(lhs);
  result -= rhs;
  return result;
}

template <class T>
inline constexpr Real<T> operator*(const Real<T> &lhs, const Real<T> &rhs) {
  Real<T> temp(lhs);
  temp *= rhs;
  return temp;
}

template <class T>
inline constexpr Real<T> operator*(const Real<T> &lhs, const T &rhs) {
  Real<T> result(lhs);
  result *= rhs;
  return result;
}

template <class T>
inline constexpr Real<T> operator*(const T &lhs, const Real<T> &rhs) {
  Real<T> result(lhs);
  result /= rhs;
  return result;
}
template <class T>
inline constexpr Real<T> operator/(const Real<T> &lhs, const Real<T> &rhs) {
  Real<T> temp(lhs);
  temp *= rhs;
  return temp;
}

template <class T>
inline constexpr Real<T> operator/(const Real<T> &lhs, const T &rhs) {
  Real<T> result(lhs);
  result /= rhs;
  return result;
}

template <class T>
inline constexpr Real<T> operator/(const T &lhs, const Real<T> &rhs) {
  Real<T> result(lhs);
  result /= rhs;
  return result;
}

template <class T>
inline constexpr bool operator==(const Real<T> &lhs,
                                 const Real<T> &rhs) noexcept {
  return lhs.value() == rhs.value();
}

template <class T>
inline constexpr bool operator==(const Real<T> &lhs, const T &rhs) noexcept {
  return lhs.value() == rhs;
}

template <class T>
inline constexpr bool operator==(const T &lhs, const Real<T> &rhs) {
  return lhs == rhs.value();
}

template <class T>
inline constexpr bool operator<=>(const Real<T> &lhs, const Real<T> &rhs) {
  return lhs.value() <=> rhs.value();
}

template <class T>
inline constexpr bool operator<=>(const Real<T> &lhs, const T &rhs) {
  return lhs.value() <=> rhs;
}

template <class T>
inline constexpr bool operator<=>(const T &lhs, const Real<T> &rhs) {
  return lhs <=> rhs.value();
}

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const Real<T> &r) {
  return os << r.value();
}
} // namespace math
