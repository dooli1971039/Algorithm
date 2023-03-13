#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dp[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 입력
    int arr[10][10] = {
        0,
    };
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            cin >> arr[i][j];
        }
    }

    int x = 1, y = 1;
    int mmax = arr[1][1];

    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            if (arr[i][j] > mmax) {
                mmax = arr[i][j];
                x = i;
                y = j;
            }
        }
    }

    cout << mmax << "\n" << x << " " << y;
}