#include <iostream>

int main() {
  unsigned long long R = 0;
  std::cin >> R;

  // Защита от некорректного ввода
  if (R == 0) {
    std::cout << 1 << std::endl;
    return 0;
  }

  unsigned long long R_squared = R * R;
  unsigned long long count_quarter = 0;
  unsigned long long x = R;

  for (unsigned long long y = 1; y < R; ++y) {
    unsigned long long y_squared = y * y;

    // Уменьшаем x пока точка вне круга
    while (x > 0 && x * x + y_squared > R_squared) {
      --x;
    }

    count_quarter += x;
  }

  // Четыре четверти + оси + центр
  unsigned long long total = count_quarter * 4 + R * 4 + 1;

  std::cout << total << std::endl;
  return 0;
}