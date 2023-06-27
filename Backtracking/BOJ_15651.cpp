#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> result(8, 0);

void back(int cnt) {
    if (cnt == m) {
        // 출력
        for (int i = 0; i < m; i++) {
            cout << result[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        result[cnt] = i;
        back(cnt + 1);
    }
}

int main() {
    cin >> n >> m;

    back(0);
}