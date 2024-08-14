#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>

int main(void) {
  uint64_t n;
  std::cin >> n;

  while (n != 1) {
    std::cout << n << ' ';
    n = n % 2 == 0 ? n / 2 : n * 3 + 1;
  }

  std::cout << 1 << std::endl;

  return EXIT_SUCCESS;
}
