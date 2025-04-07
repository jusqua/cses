#include <cstdint>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(void) {
  uint64_t n;
  cin >> n;

  while (n != 1) {
    cout << n << ' ';
    n = n % 2 == 0 ? n / 2 : n * 3 + 1;
  }

  cout << 1 << endl;

  return EXIT_SUCCESS;
}
