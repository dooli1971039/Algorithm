#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<vector<int>> arr;
vector<vector<int>> rotatingArr;

vector<vector<int>> kArr;

int orderResult[6];
bool used[6];

int minimumResult = 1e5;

int calcRow(int r) {
    int ssum = 0;
    for (int i = 1; i <= m; i++) {
        ssum += rotatingArr[r][i];
    }
    return ssum;
}

int calcArr() {
    int mmin = 1e5;
    for (int i = 1; i <= n; i++) {
        mmin = min(mmin, calcRow(i));
    }
    return mmin;
}

void rotateBorder(int r, int c, int s) {
    int LT = rotatingArr[r - s + 1][c - s];
    int RT = rotatingArr[r - s][c + s - 1];
    int LB = rotatingArr[r + s][c - s + 1];
    int RB = rotatingArr[r + s - 1][c + s];

    for (int i = c + s - 1; i > c - s; i--) {
        rotatingArr[r - s][i] = rotatingArr[r - s][i - 1];
    }
    for (int i = c - s + 1; i < c + s; i++) {
        rotatingArr[r + s][i] = rotatingArr[r + s][i + 1];
    }
    for (int i = r - s + 1; i < r + s; i++) {
        rotatingArr[i][c - s] = rotatingArr[i + 1][c - s];
    }
    for (int i = r + s - 1; i > r - s; i--) {
        rotatingArr[i][c + s] = rotatingArr[i - 1][c + s];
    }
    rotatingArr[r - s][c - s] = LT;
    rotatingArr[r - s][c + s] = RT;
    rotatingArr[r + s][c - s] = LB;
    rotatingArr[r + s][c + s] = RB;
}

void rotate(int r, int c, int s) {
    for (int i = 1; i <= s; i++) {
        rotateBorder(r, c, i);
    }
}

void rotateArr() {
    for (int i = 0; i < k; i++) {
        int order = orderResult[i];
        int r = kArr[order][0], c = kArr[order][1], s = kArr[order][2];

        rotate(r, c, s);
    }
}

void decideOrder(int cnt) {
    if (cnt == k) {
        // 순서대로 연산을 수행하고 결과 업데이트
        copy(arr.begin(), arr.end(), rotatingArr.begin());
        rotateArr();

        int num = calcArr();
        minimumResult = min(minimumResult, num);
        return;
    }

    for (int i = 0; i < k; i++) {
        if (!used[i]) {
            used[i] = true;
            orderResult[cnt] = i;
            decideOrder(cnt + 1);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n >> m >> k;

    arr.assign(n + 1, vector<int>(m + 1, 0));
    rotatingArr.assign(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    int r, c, s;
    for (int i = 0; i < k; i++) {
        cin >> r >> c >> s;
        vector<int> tmp = {r, c, s};
        kArr.push_back(tmp);
    }

    decideOrder(0);
    cout << minimumResult;
}