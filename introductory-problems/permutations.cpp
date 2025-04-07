#include <cstdint>
#include <iostream>

using namespace std;

int main(void) {
    int64_t n;
    cin >> n;

    if (n < 4 && n > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    for (int64_t i = 2; i <= n; i += 2) {
        cout << i << ' ';
    }
    for (int64_t i = 1; i <= n; i += 2) {
        cout << i << ' ';
    }

    cout << endl;

    return 0;
}
