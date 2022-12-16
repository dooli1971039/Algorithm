#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solution() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin() + 1, arr.end());

    int idx = 1;
    int tower = arr[0];
    while (tower < arr[n - 1]) {
        if (tower < arr[idx]) {
            int dif = arr[idx] - tower;
            if (dif % 2 == 0)
                tower += dif / 2;
            else
                tower += (dif / 2 + 1);

            arr[idx] = 0; // 다시 쓸 일이 없으므로 그냥 0 대입 (얼마나 감소했는지 계산할 필요 X)
        }
        idx++;
    }
    cout << tower << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        solution();
    }
}