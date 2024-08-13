#include <cstdint>
#include <iostream>

int main(void) {
    int64_t n;
    std::cin >> n;

    if (n < 4 && n > 1) {
        std::cout << "NO SOLUTION" << std::endl;
        return 0;
    }

    for (int64_t i = 2; i <= n; i += 2) {
        std::cout << i << ' ';
    }
    for (int64_t i = 1; i <= n; i += 2) {
        std::cout << i << ' ';
    }

    std::cout << std::endl;

    return 0;
}
