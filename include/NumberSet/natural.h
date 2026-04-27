#pragma once
#include <concepts>
#include <ostream>
#include <type_traits>

namespace math {
template <std::unsigned_integral T> class Natural {
  static_assert(std::is_integral_v<T>, "Natural<T> requires an integral type");

public:
  constexpr Natural(T v) noexcept : value(v) {}

  constexpr friend Natural operator+(const Natural &lhs,
                                     const Natural &rhs) noexcept {
    return lhs.value + rhs.value;
  }
  constexpr friend Natural operator*(const Natural &lhs,
                                     const Natural &rhs) noexcept {
    return lhs.value * rhs.value;
  }
  constexpr Natural &operator+=(const Natural &others) noexcept {
    value += others.value;
    return *this;
  }
  constexpr Natural &operator*=(const Natural &others) noexcept {
    value *= others.value;
    return *this;
  }

public:
  friend std::ostream &operator<<(std::ostream &os, const Natural &n) {
    return os << n.value;
  }

private:
  T value = {};
};
} // namespace math
