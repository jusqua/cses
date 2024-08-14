#include <cstdint>
#include <iostream>

int main(void) {
    int64_t n, prev, curr, diff, count = 0;
    std::cin >> n >> prev;

    for (int64_t i = 1; i < n; i++) {
        std::cin >> curr;
        diff = prev - curr;
        if (diff > 0)
            count += diff;
        else
            prev = curr;
    }

    std::cout << count << std::endl;

    return 0;
}
