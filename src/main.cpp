#include <cstdint>
#include <iostream>

#include "point_counter.h"

int main() {
  std::uint64_t R = 0;
  if (!(std::cin >> R)) {
    std::cerr << "Error: invalid input\n";
    return 1;
  }

  if (R > 2'000'000'000) {
    std::cerr << "Error: radius too large (max 2e9)\n";
    return 1;
  }
  if (R == 0) {
    std::cout << 1 << '\n';
    return 0;
  }

  std::cout << countPointsInCircle(R) << '\n';
  return 0;
}