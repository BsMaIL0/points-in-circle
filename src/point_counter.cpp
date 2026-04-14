#include "point_counter.h"

std::uint64_t countPointsInCircle(std::uint64_t radius) noexcept {
    std::uint64_t R_squared = radius * radius;
    std::uint64_t count_quarter = 0;
    std::uint64_t x = radius;

    for (std::uint64_t y = 1; y < radius; ++y) {
        std::uint64_t y_squared = y * y;

        // Уменьшаем x пока точка вне круга
        while (x > 0 && x * x + y_squared > R_squared) {
            --x;
        }

        count_quarter += x;
    }

    // Четыре четверти + оси + центр
    uint64_t total = count_quarter * 4 + radius * 4 + 1;
    
    return total;
}