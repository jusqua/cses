#include <cstdint>
#include <iostream>

using namespace std;

int main(void) {
    uint64_t N;
    cin >> N;

    int64_t a, b, high, low, diff;
    while (N--) {
        cin >> a >> b;

        // Get the high and low
        if (a > b) {
            high = a;
            low = b;
        } else {
            high = b;
            low = a;
        }

        // Remove the inequalities
        diff = high - low;
        high -= diff * 2;
        low -= diff;

        // The piles must be equal and divisible by 3
        if (low >= 0 && high % 3 == 0 && high == low) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
