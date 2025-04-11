#include <iostream>
#include <array>

using namespace std;

constexpr int N = 8;
constexpr char VALID_ROOM = '.';
constexpr char INVALID_ROOM = '*';

int nqueens(array<string, N>& board, int column) {
    if (column == N) {
        return 1;
    }

    int sum = 0;
    for (int row = 0; row < N; ++row) {
        if (board[row][column] == INVALID_ROOM) {
            continue;
        }

        auto b = board;
        b[row][column] = INVALID_ROOM;

        // Horizontal
        for (int i = 1; column + i < N; ++i) {
            b[row][column + i] = INVALID_ROOM;
        }

        // Downward diagonal
        for (int i = 1; row + i < N && column + i < N; ++i) {
            b[row + i][column + i] = INVALID_ROOM;
        }

        // Upward diagonal
        for (int i = 1; row - i >= 0 && column + i < N; ++i) {
            b[row - i][column + i] = INVALID_ROOM;
        }

        sum += nqueens(b, column + 1);
    }

    return sum;
}

int main(void) {
    array<string, N> board;
    for (int i = 0; i < N; ++i) cin >> board[i];

    cout << nqueens(board, 0) << endl;
}
