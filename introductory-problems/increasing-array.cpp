#include <cstdint>
#include <iostream>

using namespace std;

int main(void) {
    int64_t n, prev, curr, diff, count = 0;
    cin >> n >> prev;

    for (int64_t i = 1; i < n; i++) {
        cin >> curr;
        diff = prev - curr;
        if (diff > 0)
            count += diff;
        else
            prev = curr;
    }

    cout << count << endl;

    return 0;
}
