#pragma once
#include <concepts>

namespace math {
template <std::integral T> class Zahlen {
public:
  constexpr friend Zahlen operator+(const Zahlen &lhs, const Zahlen &rhs) {
    return lhs.value + rhs.value;
  }
  constexpr friend Zahlen operator-(const Zahlen &lhs, const Zahlen &rhs) {
    return lhs.value - rhs.value;
  }
  constexpr friend Zahlen operator*(const Zahlen &lhs, const Zahlen &rhs) {
    return lhs.value * rhs.value;
  }
  constexpr Zahlen &operator+=(const Zahlen &others) {
    return value + others.value;
    return *this;
  }
  constexpr Zahlen &operator-=(const Zahlen &others) {
    return value - others.value;
    return *this;
  }
  constexpr Zahlen &operator*=(const Zahlen &others) {
    return value * others.value;
    return *this;
  }

private:
  T value;
};
} // namespace math
