#include <iostream>
using namespace std;

int arr[2288][2288]; // 3^7=2287
int n;

int cnt[3] = {0, 0, 0}; //-1, 0, 1

/**
 * 1. 종이가 다 같은 수로 채워져 있는지 체크
 * 2-1. 그렇지 않으면 분할
 * 2-2. 다 같은 수이면 종이 개수 증가
 */

bool check(int stR, int stC, int len) {
    int num = arr[stR][stC];

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (num != arr[stR + i][stC + j]) {
                return false;
            }
        }
    }
    return true;
}

void checkAndDivide(int stR, int stC, int len) {
    if (len == 1 || check(stR, stC, len)) { // 2-2. 다 같은 수일 때
        cnt[arr[stR][stC] + 1]++;
        return;
    }

    len = len / 3;
    checkAndDivide(stR, stC, len);
    checkAndDivide(stR, stC + len, len);
    checkAndDivide(stR, stC + 2 * len, len);

    checkAndDivide(stR + len, stC, len);
    checkAndDivide(stR + len, stC + len, len);
    checkAndDivide(stR + len, stC + 2 * len, len);

    checkAndDivide(stR + 2 * len, stC, len);
    checkAndDivide(stR + 2 * len, stC + len, len);
    checkAndDivide(stR + 2 * len, stC + 2 * len, len);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    checkAndDivide(0, 0, n);
    cout << cnt[0] << "\n" << cnt[1] << "\n" << cnt[2];
}