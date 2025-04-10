#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int64_t _min_diff(int N, vector<int64_t>& P, int64_t left_sum, int64_t right_sum, int index) {
    if (index == N)
        return abs(left_sum - right_sum);

    return min(_min_diff(N, P, left_sum + P[index], right_sum, index + 1),
               _min_diff(N, P, left_sum, right_sum + P[index], index + 1));
}

int64_t min_diff(int N, vector<int64_t>& P) {
    return _min_diff(N, P, 0, 0, 0);
}

int main(void) {
    int N;
    cin >> N;

    vector<int64_t> P(N);
    for (int i = 0; i < N; ++i) cin >> P[i];

    cout << min_diff(N, P) << endl;
}
