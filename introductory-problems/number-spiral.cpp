#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

int main(void) {
    int64_t n, col, row, num_rooms, min_value, max_value, ring;
    cin >> n;

    for (int64_t i = 0; i < n; i++) {
        cin >> row >> col;

        // Get current ring
        ring = max(col, row);
        // Get ring number of rooms (Arithmetic Progression)
        num_rooms = 1 + 2 * (ring - 1);
        // Get ring max value (Arithmetic Progression Sum)
        max_value = ((num_rooms + 1) / 2) * ring;
        // Get ring min value
        min_value = max_value - num_rooms + 1;

        if (col < row) {
            cout << (ring % 2 == 0 ? max_value - col + 1 : min_value + col - 1) << endl;
        } else if (col > row) {
            cout << (ring % 2 == 0 ? min_value + row - 1 : max_value - row + 1) << endl;
        } else {
            cout << min_value + ring - 1 << endl;
        }
    }
}
