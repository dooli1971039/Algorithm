#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr(31, 0);
    int num = 0;
    for (int i = 0; i < 28; i++) {
        cin >> num;
        arr[num] = 1;
    }

    for (int i = 1; i <= 30; i++) {
        if (arr[i] == 0) {
            cout << i << '\n';
        }
    }
}
