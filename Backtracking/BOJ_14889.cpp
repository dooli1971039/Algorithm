#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int arr[21][21];
bool used[21];

int n;
int minGap = 2005;

// 팀을 나누는 함수 - used 배열(true/false)로 팀 구분
void back(int cnt, int before) {
    if (cnt == n / 2) {
        int aSum = 0;
        int bSum = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j)
                    continue;

                if (used[i] && used[j]) { // a팀
                    aSum += (arr[i][j] + arr[j][i]);
                } else if (!used[i] && !used[j]) { // b팀
                    bSum += (arr[i][j] + arr[j][i]);
                }
            }
        }

        /**
         * (1,3)이 같은 팀일 때, 위의 for문에서
         * i=1, j=3일 때와 i=3, j=1일때를 모두 sum에 더하기 때문에
         * 두 팀의 능력치 차이를 구할 때 aSum/2, bSum/2와 같이 2로 나누어서 계산해야 한다.
         */

        minGap = min(minGap, abs(aSum / 2 - bSum / 2));
        return;
    }

    for (int i = before + 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = true;
            back(cnt + 1, i);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    back(0, 0);
    cout << minGap;
}