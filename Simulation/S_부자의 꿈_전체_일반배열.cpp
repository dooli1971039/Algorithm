#include <iostream>
using namespace std;

bool checkRowAndColumn(int *arr[], int n, int m, int r, int c) {
    int num = arr[r][c];
    for (int i = 1; i <= n; i++) {
        if (num < arr[i][c])
            return false;
    }
    for (int j = 1; j <= m; j++) {
        if (num < arr[r][j])
            return false;
    }

    return true;
}

int checkArray(int *arr[], int *maxArr[], int n, int m) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            maxArr[i][j] = 0;
            if (checkRowAndColumn(arr, n, m, i, j)) {
                maxArr[i][j] = arr[i][j];
                cnt++;
            }
        }
    }

    return cnt;
}

void solution(int tCase) {
    int n, m, q;
    cin >> n >> m >> q;

    int *arr[n + 1];
    int *maxArr[n + 1];
    for (int i = 1; i < n + 1; i++) {
        arr[i] = new int[m + 1];
        maxArr[i] = new int[m + 1];
        for (int j = 1; j < m + 1; j++) {
            cin >> arr[i][j];
            maxArr[i][j] = 0;
        }
    }
    int count = 0;
    int beforeCount = 0;
    int r, c;
    while (q--) {
        cin >> r >> c >> arr[r][c];
        if (maxArr[r][c] != 0 && maxArr[r][c] <= arr[r][c]) {
            count += beforeCount;
            continue;
        }
        beforeCount = checkArray(arr, maxArr, n, m);
        count += beforeCount;
    }

    cout << '#' << tCase << ' ' << count << '\n';
}

int main() {
    int testCase;
    cin >> testCase;

    for (int i = 1; i <= testCase; i++)
        solution(i);
    return 0;
}