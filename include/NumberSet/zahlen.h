#pragma once
#include <concepts>
#include <ostream>

namespace math {
template <std::integral T> class Zahlen {
public:
  constexpr Zahlen(T v) noexcept : value(v) {}

public:
  constexpr friend Zahlen operator+(const Zahlen &lhs,
                                    const Zahlen &rhs) noexcept {
    return lhs.value + rhs.value;
  }
  constexpr friend Zahlen operator-(const Zahlen &lhs,
                                    const Zahlen &rhs) noexcept {
    return lhs.value - rhs.value;
  }
  constexpr friend Zahlen operator*(const Zahlen &lhs,
                                    const Zahlen &rhs) noexcept {
    return lhs.value * rhs.value;
  }
  constexpr Zahlen &operator+=(const Zahlen &others) noexcept {
    return value + others.value;
    return *this;
  }
  constexpr Zahlen &operator-=(const Zahlen &others) noexcept {
    return value - others.value;
    return *this;
  }
  constexpr Zahlen &operator*=(const Zahlen &others) noexcept {
    return value * others.value;
    return *this;
  }

public:
  friend std::ostream &operator<<(std::ostream &o, const Zahlen &z) {
    return o << z.value;
  }

private:
  T value;
};
} // namespace math
