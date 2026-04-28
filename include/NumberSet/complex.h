#pragma once
#include <complex>
#include <ostream>

namespace math {
template <typename T> using Complex = std::complex<T>;

template <typename T>
std::ostream &operator<<(std::ostream &os, const Complex<T> &c) {
  os << c.real() << " + " << c.imag() << "i";
  return os;
}

} // namespace math
