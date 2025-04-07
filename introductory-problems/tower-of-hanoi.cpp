#include <iostream>

using namespace std;

void hanoi(int n, int from, int to, int aux) {
    // Base case: if there is only one disk, move it directly
    if (n == 1) {
        cout << from << " " << to << endl;
        return;
    }

    // Move n-1 disks from 'from' to 'aux' using 'to' as auxiliary
    hanoi(n - 1, from, aux, to);
    // Move the largest disk from 'from' to 'to'
    cout << from << " " << to << endl;
    // Move n-1 disks from 'aux' to 'to' using 'from' as auxiliary
    hanoi(n - 1, aux, to, from);
}

int main(void) {
    int N;
    cin >> N;

    // Calculate the minimum number of moves required
    cout << (1u << N) - 1 << endl;
    hanoi(N, 1, 3, 2);
}
