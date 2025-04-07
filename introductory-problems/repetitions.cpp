#include <cstdint>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(void) {
  char curr, prev;
  uint64_t count, max_count;

  cin >> prev;
  count = 1;
  max_count = count;

  while (cin >> curr) {
    if (curr == prev) {
      count++;
    } else {
      max_count = max(count, max_count);
      count = 1;
    }
    prev = curr;
  }

  max_count = max(count, max_count);

  cout << max_count << endl;

  return EXIT_SUCCESS;
}
