#include <cstdint>
#include <iostream>

#define LIMIT 1000000007

using namespace std;

int main(void) {
    uint64_t result = 1, base = 2, exponent;
    cin >> exponent;

    // https://www.geeksforgeeks.org/fast-exponention-using-bit-manipulation/
    uint64_t a = base, b = exponent;
    while (b > 0) {
        if (b & 1)
            result = result * a % LIMIT;

        a = a * a % LIMIT;
        b >>= 1;
    }

    cout << result << endl;
    return 0;
}
