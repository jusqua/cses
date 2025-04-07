#include <cstdint>
#include <iostream>

using namespace std;

int main(void) {
    uint64_t N;
    cin >> N;

    // https://www.purplemath.com/modules/factzero.htm
    // Basically if the number have factors of the number have 5s in it, sum to the count
    // Because the trailing zeros is formed by the 2 * 5 factors
    // And exists more 2s than 5s, so exists a 2 for every 5 in the factorial numbers
    // Find all values with 5 factor and done
    uint64_t trailing_zeros = 0;
    N /= 5;
    while (N > 0) {
        trailing_zeros += N;
        N /= 5;
    }

    cout << trailing_zeros << endl;
}
