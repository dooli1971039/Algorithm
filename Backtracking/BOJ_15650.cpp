#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> result(8, 0);
vector<bool> used(9, false);

void back(int cnt, int before) {
    if (cnt == m) {
        // 여기서 출력 후 return
        for (int i = 0; i < cnt; i++) {
            cout << result[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for (int i = before + 1; i <= n; i++) {
        if (!used[i]) { // 사용되지 않았을 때
            used[i] = true;
            result[cnt] = i;
            back(cnt + 1, i);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;

    back(0, 0);
}