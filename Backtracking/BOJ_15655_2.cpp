#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<int> result(8, 0);
vector<int> arr;
vector<bool> used(8, false);

void back(int cnt, int before_idx) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = before_idx + 1; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            result[cnt] = arr[i];
            back(cnt + 1, i);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    arr.assign(n, 0); // 여기서 초기화를 크기 n만큼 초기화를 할 것

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    back(0, -1);
}