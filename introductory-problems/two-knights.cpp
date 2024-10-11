#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    uint64_t N;
    uint64_t combination = 0;
    uint64_t restriction = 0;
    uint64_t isqr = 0;

    cin >> N;

    // 1² board
    cout << 0 << endl;

    // n² board
    for (uint64_t i = 2; i <= N; i++) {
        // i²
        isqr = i * i;

        // i² choose 2
        combination = isqr * (isqr - 1) / 2;

        // reachabled rooms
        restriction += 8 * (i - 2);

        cout << combination - restriction << endl;
    }
}
