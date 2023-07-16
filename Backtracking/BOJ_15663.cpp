#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;
vector<int> used(8, 0);
vector<int> result(8, 0);

void back(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int check_duplicate = -1;
    for (int i = 0; i < n; i++) {
        if (!used[i] && check_duplicate != arr[i]) {
            check_duplicate = arr[i];
            used[i] = true;
            result[cnt] = arr[i];
            back(cnt + 1);
            used[i] = false;
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

    back(0);
}