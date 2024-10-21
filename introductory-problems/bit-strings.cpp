#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define LIMIT 1000000007
#define debug(var) (std::cout << #var << " = " << var << endl)
using namespace std;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

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
