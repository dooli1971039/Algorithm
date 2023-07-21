#include <iostream>
#include <vector>
using namespace std;

int rowReturnBiggest(vector<int> &row, int r, int m) {
    int num = row[1];
    int c = 1;
    for (int i = 2; i <= m; i++) {
        if (num < row[i]) {
            num = row[i];
            c = i;
        }
    }

    return c;
}

bool checkPointIsBigInColumn(vector<vector<int>> &arr, int num, int c, int n) {
    for (int i = 1; i <= n; i++)
        if (num < arr[i][c])
            return false;
    return true;
}

int checkArray(vector<vector<int>> &arr, vector<vector<bool>> &maxArr, int n, int m) {
    // 각 row를 먼저 체크하고, 가장 큰 부분의 좌표를 저장하자.
    vector<pair<int, int>> rowBiggest;
    for (int i = 1; i <= n; i++)
        rowBiggest.push_back({i, rowReturnBiggest(arr[i], i, m)});

    int cnt = 0;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++)
            arr[i][j] = false;

    for (int i = 0; i < rowBiggest.size(); i++)
        // 해당 좌표가 해당 column에서 제일 큰지 체크
        if (checkPointIsBigInColumn(arr, arr[rowBiggest[i].first][rowBiggest[i].second], rowBiggest[i].second, n)) {
            cnt++;
            maxArr[rowBiggest[i].first][rowBiggest[i].second] = true;
        }

    return cnt;
}

void solution(int tCase) {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
    vector<vector<bool>> maxArr(n + 1, vector<bool>(m + 1, 0));
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++)
            cin >> arr[i][j];

    int beforeCount = 0;
    int count = 0;
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