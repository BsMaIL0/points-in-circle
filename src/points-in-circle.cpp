#include <iostream>
#include <cstdint>
#include "point_counter.h"

int main() {
  std::uint64_t R = 0;
  std::cin >> R;

  if (R == 0) {
    std::cout << 1 << std::endl;
    return 0;
  }

  std::cout << countPointsInCircle(R) << std::endl;
  return 0;
}