#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> number;
vector<int> result(9, 0);
vector<bool> used(9, false);

void back(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            result[cnt] = number[i];
            back(cnt + 1);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    number.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> number[i];
    }
    sort(number.begin(), number.end());
    back(0);
}