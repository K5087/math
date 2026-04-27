#pragma once
#include <concepts>
#include <type_traits>

namespace math {
template <std::unsigned_integral T> class Natural {
  static_assert(std::is_integral_v<T>, "Natural<T> requires an integral type");

  constexpr friend Natural operator+(const Natural &lhs, const Natural &rhs) {
    return lhs.value + rhs.value;
  }
  constexpr friend Natural operator*(const Natural &lhs, const Natural &rhs) {
    return lhs.value * rhs.value;
  }
  constexpr Natural &operator+=(const Natural &others) {
    return value + others.value;
    return *this;
  }
  constexpr Natural &operator*=(const Natural &others) {
    return value * others.value;
    return *this;
  }

private:
  T value = {};
};
} // namespace math
