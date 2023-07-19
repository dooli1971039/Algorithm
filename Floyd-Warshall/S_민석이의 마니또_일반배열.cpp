#include <algorithm>
#include <iostream>
#define INF 1e5 + 1
using namespace std;

// vector보다 배열의 실행시간이 훨씬 짧다.
int arr[401][401];

void floydWarshall(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j)
                    continue;
                // k 지점을 지나는 것이 더 저렴할 경우 업데이트
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
}

/*
 * 마니또 관계들 중 cost 가장 적은 사이클 탐색 및 해당 cost 반환
 * - 자기 자신과의 마니또 관계가 있을 수 있기 때문에 x와 y가 같은 경우를 체크해야 한다.
 * - 사이클이 없는 경우, mmin 값이 업데이트 되지 않을 것이므로 체크하여 -1을 반환한다.
 */
int findMinCostCycle(pair<int, int> friends[], int m) {
    int mmin = INF;

    for (int i = 0; i < m; i++) {
        int x = friends[i].first;
        int y = friends[i].second;

        if (x != y) {
            mmin = min(arr[x][y] + arr[y][x], mmin);
        } else {
            mmin = min(arr[x][x], mmin); // 자기 자신과의 마니또
        }
    }

    if (mmin == INF)
        return -1;
    return mmin;
}

void solution(int tCase) {
    int n, m;
    cin >> n >> m; // 학생 수, 마니또 관계의 수

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = INF;
        }
    }

    int x, y, c;
    pair<int, int> friends[m];
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> arr[x][y];
        friends[i] = {x, y}; // 마니또 관계 노드 저장
    }

    floydWarshall(n);
    cout << '#' << tCase << ' ' << findMinCostCycle(friends, m) << '\n';
}

int main() {
    int testCase;
    cin >> testCase;

    for (int i = 1; i <= testCase; i++)
        solution(i);
    return 0;
}