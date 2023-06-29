#include <iostream>
using namespace std;

void calc_dp() {
    int n;
    cin >> n;
    int arr[n + 1] = {
        0,
    };

    arr[1] = 1;
    arr[2] = 2; // 1 1, 2
    arr[3] = 4; // 1 1 1, 1 2, 2 1, 3

    for (int i = 4; i <= n; i++) {
        arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
    }
    cout << arr[n] << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        calc_dp();
    }
}