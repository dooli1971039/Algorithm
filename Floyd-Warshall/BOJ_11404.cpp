#include <iostream>

using namespace std;

int arr[101][101];
const int INF = 987654321;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = INF;
        }
        arr[i][i] = 0;
    }

    // 값 입력
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        // 두 정점 사이의 길이 여러개일 수 있다.
        arr[a][b] = min(c, arr[a][b]);
    }

    // 플로이드워셜
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == INF) // 갈 수 없는 경우에 0으로 출력
                cout << 0 << ' ';
            else
                cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}