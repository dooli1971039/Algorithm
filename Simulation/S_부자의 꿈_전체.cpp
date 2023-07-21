#include <iostream>
#include <vector>
using namespace std;

bool checkRowAndColumn(vector<vector<int>> &arr, int n, int m, int r, int c) {
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

int checkArray(vector<vector<int>> &arr, vector<vector<bool>> &maxArr, int n, int m) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            maxArr[i][j] = false;
            if (checkRowAndColumn(arr, n, m, i, j)) {
                maxArr[i][j] = true;
                cnt++;
            }
        }
    }

    return cnt;
}

void solution(int tCase) {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
    vector<vector<bool>> maxArr(n + 1, vector<bool>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    int count = 0;
    int beforeCount = 0;
    int r, c;
    while (q--) {
        cin >> r >> c >> arr[r][c];
        // 새로 입력한 것이 이전에도 안전했으면
        if (maxArr[r][c]) {
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