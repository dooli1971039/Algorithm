#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;
vector<int> result(8, 0);

void back(int cnt, int before_idx) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int check_duplicate = -1;
    for (int i = before_idx + 1; i < n; i++) {
        if (check_duplicate != arr[i]) {
            check_duplicate = arr[i];
            result[cnt] = arr[i];
            back(cnt + 1, i);
        }
    }
}

int main() {
    cin >> n >> m;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    back(0, -1);
}