#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int32_t N;
    cin >> N;

    // Reserve space for each code
    vector<vector<bool>> codes;
    codes.reserve(pow(2, N));

    // Emplace the first and second iteretation
    vector<bool> first(N, 0);
    codes.emplace_back(first);
    vector<bool> second(N, 0);
    second.back() = 1;
    codes.emplace_back(second);

    // For the n-th position iterates over the codes
    for (int64_t i = N - 2; i >= 0; --i) {
        // Look up from the last to the first and emplace the new code with a 1 at the n-th position
        for (int64_t j = codes.size() - 1; j >= 0; --j) {
            vector<bool> code(codes[j]);
            code.at(i) = 1;
            codes.emplace_back(code);
        }
    }

    // Display each code
    for (auto code : codes) {
        for (uint64_t i = 0, n = code.size(); i < n; ++i)
            cout << static_cast<int>(code[i]);
        cout << endl;
    }

    return 0;
}
