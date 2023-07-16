#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> result(8, 0);

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
        result[cnt] = i;
        back(cnt + 1, i);
    }
}

int main() {
    cin >> n >> m;

    back(0, 0);
}