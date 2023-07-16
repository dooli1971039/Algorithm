#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> result(8, 0);

void back(int cnt, int before) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << result[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for (int i = before; i <= n; i++) {
        result[cnt] = i;
        back(cnt + 1, i);
    }
}

int main() {
    cin >> n >> m;
    back(0, 1);
}