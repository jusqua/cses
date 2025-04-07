#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  uint64_t n;
  cin >> n;

  uint64_t num;
  auto found = vector<bool>(n, false);

  for (uint64_t i = 0; i < n - 1; i++) {
    cin >> num;
    found[num - 1] = true;
  }

  cout << find(found.begin(), found.end(), false) - found.begin() + 1 << endl;

  return EXIT_SUCCESS;
}
