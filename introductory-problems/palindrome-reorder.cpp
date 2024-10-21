#include <cstdint>
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define debug(var) (std::cout << #var << " = " << var << endl)
using namespace std;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    constexpr int LETTERS = 26;

    array<uint64_t, LETTERS> letters;
    letters.fill(0);

    string word;
    cin >> word;

    int32_t index = -1;
    uint64_t half = 0;
    uint64_t odds = 0;
    uint64_t n = word.size();

    // Get word count
    for (uint64_t i = 0; i < n; ++i)
        letters[word[i] - 'A']++;

    // Find the odds
    for (int32_t i = 0; i < LETTERS; ++i) {
        if (letters[i] & 1) {
            odds++;
            index = i;
        }
    }

    // Word with odd size must have only one odd
    // Word with even size must have no odds
    if ((n & 1 && odds != 1) || (!(n & 1) && odds)) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    // Print left side
    for (int32_t i = 0; i < LETTERS; ++i) {
        if (i == index) continue;
        half = letters[i] / 2;
        for (uint64_t j = 0; j < half; j++)
            cout << static_cast<char>('A' + i);
    }

    // Print odd value
    if (odds) {
        for (uint64_t j = 0; j < letters[index]; j++)
            cout << static_cast<char>('A' + index);
    }

    // Print right side
    for (int32_t i = LETTERS - 1; i >= 0; --i) {
        if (i == index) continue;
        half = letters[i] / 2;
        for (uint64_t j = 0; j < half; j++)
            cout << static_cast<char>('A' + i);
    }

    cout << endl;

    return 0;
}
