#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

int64_t findDigit(int64_t position) {
    int64_t length = 1;
    int64_t count = 9;
    int64_t start = 1;

    // d * 9 * 10^(d - 1)
    // position - 9 - 180 - 2700 - 36000 - ...
    while (position > length * count) {
        position -= length * count;
        length++;
        count *= 10;
        start *= 10;
    }

    // the power of 10 + the calculated offset
    // calculated offset = position relative to 0-index / number of digits
    int64_t number = start + (position - 1) / length;

    // which digit in the number 0-indexed
    int64_t index = (position - 1) % length;

    return number / static_cast<int64_t>(pow(10, length - index - 1)) % 10;
}

int main(void) {
    int queries;
    cin >> queries;

    while (queries--) {
        int64_t position;
        cin >> position;
        cout << findDigit(position) << endl;
    }
}
