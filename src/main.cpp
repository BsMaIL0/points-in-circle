#include <cstdint>
#include <iostream>

#include "point_counter.h"

int main() {
  std::uint64_t R = 0;
  std::cin >> R;

  if (R == 0) {
    std::cout << 1 << '\n';
    return 0;
  }

  std::cout << countPointsInCircle(R) << '\n';
  return 0;
}