#include "NumberSet/natural.h"
#include <iostream>
using N = math::Natural<unsigned int>;

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
  N a = 1u;
  N b(2);
  N c = a + b;
  std::cout << c;
  return 0;
}
