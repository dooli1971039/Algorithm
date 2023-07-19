#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> result(6, 0);

int k;

void back(int cnt, int before) {
    if (cnt == 6) {
        for (int i = 0; i < 6; i++) {
            cout << result[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for (int i = before + 1; i < k; i++) {
        result[cnt] = arr[i];
        back(cnt + 1, i);
    }
}

int main() {
    do {
        cin >> k;
        arr.assign(k, 0);

        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }

        back(0, -1);
        cout << '\n';

    } while (k != 0);
}