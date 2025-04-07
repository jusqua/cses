#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main(void) {
    string N;
    cin >> N;

    set<string> strings;

    sort(N.begin(), N.end());

    do strings.insert(N);
    while (next_permutation(N.begin(), N.end()));

    cout << strings.size() << endl;
    for (const auto& str : strings) {
        cout << str << endl;
    }
}
