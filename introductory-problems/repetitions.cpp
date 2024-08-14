#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>

int main(void) {
  char curr, prev;
  uint64_t count, max_count;

  std::cin >> prev;
  count = 1;
  max_count = count;

  while (std::cin >> curr) {
    if (curr == prev) {
      count++;
    } else {
      max_count = std::max(count, max_count);
      count = 1;
    }
    prev = curr;
  }

  max_count = std::max(count, max_count);

  std::cout << max_count << std::endl;

  return EXIT_SUCCESS;
}

