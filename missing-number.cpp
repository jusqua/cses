#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

int main(void) {
  uint64_t n;
  std::cin >> n;

  uint64_t num;
  auto found = std::vector<bool>(n, false);

  for (uint64_t i = 0; i < n - 1; i++) {
    std::cin >> num;
    found[num - 1] = true;
  }

  std::cout << std::find(found.begin(), found.end(), false) - found.begin() + 1 << std::endl;

  return EXIT_SUCCESS;
}

