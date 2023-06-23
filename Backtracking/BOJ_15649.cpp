#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> result(9, 0); // 1~8까지라서
vector<bool> used(9, false);

void back(int cnt) {
    if (cnt == m) {
        // 여기서 출력 후 return
        for (int i = 0; i < cnt; i++) {
            cout << result[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) { // 사용되지 않았을 때
            used[i] = true;
            result[cnt] = i;
            back(cnt + 1);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;

    back(0);
}