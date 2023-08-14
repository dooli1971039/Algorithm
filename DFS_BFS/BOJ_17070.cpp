#include <iostream>
#include <queue>
using namespace std;

int n;
int arr[17][17];
int count[17][17]; // 파이프를 옮길 수 있는 방법 개수
queue<pair<int, pair<int, int>>> pipes;

bool isPossible(int r, int c) { return r >= 1 && c >= 1 && r <= n && c <= n; }

void moveHorizontal(int r, int c) {
    if (isPossible(r, c + 1) && arr[r][c + 1] == 0) {
        pipes.push({1, {r, c + 1}});
        count[r][c + 1]++;
    }
}

void moveVertical(int r, int c) {
    if (isPossible(r + 1, c) && arr[r + 1][c] == 0) {
        pipes.push({2, {r + 1, c}});
        count[r + 1][c]++;
    }
}

void moveDiagonal(int r, int c) {
    if (isPossible(r + 1, c + 1) && arr[r][c + 1] == 0 && arr[r + 1][c] == 0 && arr[r + 1][c + 1] == 0) {
        pipes.push({3, {r + 1, c + 1}});
        count[r + 1][c + 1]++;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    pipes.push({1, {1, 2}});

    while (!pipes.empty()) {
        auto pipe = pipes.front();
        pipes.pop();

        int position = pipe.first;
        int r = pipe.second.first;
        int c = pipe.second.second;

        if (position == 1) { // 가로로 이동
            moveHorizontal(r, c);
            moveDiagonal(r, c);
        } else if (position == 2) { // 세로로 이동
            moveVertical(r, c);
            moveDiagonal(r, c);
        } else { // 대각선으로 이동
            moveHorizontal(r, c);
            moveVertical(r, c);
            moveDiagonal(r, c);
        }
    }

    cout << count[n][n];
}