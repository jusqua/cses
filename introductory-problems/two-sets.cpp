#include <cstdint>
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define debug(var) (std::cout << #var << " = " << var << endl)
using namespace std;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    uint64_t N;
    cin >> N;

    // Simplified arithmetic progression sum (n / 2) * ((2 * a) + (n - 1) * d)
    uint64_t apsum = (N / 2.0) * (N + 1);
    // If an odd number
    if (apsum & 1) {
        cout << "NO" << endl;
        return 0;
    }

    // The half number, the target
    uint64_t target = apsum / 2;

    cout << "YES" << endl;

    uint64_t diff = 0;
    uint64_t sum = 0;
    uint64_t elements = N;
    bool have_diff = false;

    // Calculate set bounds
    while (sum + elements <= target) {
        sum += elements--;
    }

    // Diff is the remaining element to complete the sum
    diff = target - sum;
    if (diff > 0) {
        have_diff = true;
    }

    // Print first set
    cout << N - elements + have_diff << endl;
    // Last values from the progression
    for (uint64_t i = elements + 1; i <= N; i++) {
        cout << i << ' ';
    }
    // If diff exists
    if (have_diff) {
        cout << diff << ' ';
    }
    cout << endl;

    // Second set
    cout << elements - have_diff << endl;
    // Before diff value
    for (uint64_t i = 1; i < diff; i++) {
        cout << i << ' ';
    }
    // After diff value
    for (uint64_t i = diff + 1; i <= elements; i++) {
        cout << i << ' ';
    }
    cout << endl;
}
