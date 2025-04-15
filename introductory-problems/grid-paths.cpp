#include <iostream>
#include <array>
#include <unordered_map>
#include <utility>

using namespace std;

enum Direction {
    UP = 'U',
    DOWN = 'D',
    LEFT = 'L',
    RIGHT = 'R',
    UNKNOWN = '?'
};

constexpr const static int N = 7;
constexpr const static int END = N * N - 1;

static unordered_map<char, pair<int, int>> directions;
constexpr const static array<pair<int, int>, 4> diagonals = { make_pair(-1, -1), make_pair(1, -1), make_pair(1, 1), make_pair(-1, 1) };

inline bool isValid(array<array<bool, N>, N>& visited, int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N && !visited[i][j];
}

int _findAvailablePaths(string& trajectory, array<array<bool, N>, N>& visited, int track, int i, int j) {
    if (!isValid(visited, i, j)) {
        return 0;
    }

    if (i == N - 1 && j == 0) {
        return track == END;
    }

    // Verify vertical paths
    if ((i == N - 1 || i == 0 || (visited[i - 1][j] && visited[i + 1][j])) && (j - 1 >= 0 && !visited[i][j - 1] && j + 1 < N && !visited[i][j + 1])) {
        return 0;
    }

    // Verify horizontal paths
    if ((j == N - 1 || j == 0 || (visited[i][j - 1] && visited[i][j + 1])) && (i - 1 >= 0 && !visited[i - 1][j] && i + 1 < N && !visited[i + 1][j])) {
        return 0;
    }

    // Verify isolated paths
    int invalids = 0;
    for (const auto& direction : directions) {
        auto [di, dj] = direction.second;
        invalids += i >= 0 && i < N && j >= 0 && j < N && visited[i][j];
    }
    if (invalids == 3) {
        return 0;
    }

    // Verify diagonal paths
    for (const auto& diagonal : diagonals) {
        auto [dx, dy] = diagonal;
        if (isValid(visited, i + dx, j + dy) && !isValid(visited, i, j + dy) && !isValid(visited, i + dx, j))
            return 0;
    }

    visited[i][j] = true;

    int paths = 0;
    if (trajectory[track] != UNKNOWN) {
        auto [di, dj] = directions[trajectory[track]];
        paths = _findAvailablePaths(trajectory, visited, track + 1, i + di, j + dj);
    } else {
        for (const auto& direction : directions) {
            auto [di, dj] = direction.second;
            paths += _findAvailablePaths(trajectory, visited, track + 1, i + di, j + dj);
        }
    }

    visited[i][j] = false;

    return paths;
}

int findAvailablePaths(string trajectory) {
    array<array<bool, N>, N> visited{};

    visited[0][0] = true;

    int paths = 0;
    if (trajectory[0] != UNKNOWN) {
        auto [i, j] = directions[trajectory[0]];
        paths = _findAvailablePaths(trajectory, visited, 1, i, j);
    } else {
        for (const auto& direction : directions) {
            auto [i, j] = direction.second;
            paths += _findAvailablePaths(trajectory, visited, 1, i, j);
        }
    }
    return paths;
}

int main(void) {
    directions[UP] = { -1, 0 };
    directions[DOWN] = { 1, 0 };
    directions[LEFT] = { 0, -1 };
    directions[RIGHT] = { 0, 1 };

    string trajectory;
    cin >> trajectory;

    cout << findAvailablePaths(trajectory) << endl;
}
