#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
int arr[8];
int result[8];

void back(int cnt, int cur) {
    result[cnt] = arr[cur];
    if (cnt == m - 1) { // m개 다 골랐을 때 출력 (cnt는 0부터 시작해서 m-1에서 끝남)
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = cur + 1; i < n; i++) {
        if (i < n) {
            back(cnt + 1, i);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        if (i < n) {
            back(0, i);
        }
    }
}