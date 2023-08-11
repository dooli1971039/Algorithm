#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> ssum(n - x + 1, 0);

    for (int i = 0; i < x; i++)
        ssum[0] += arr[i];

    for (int i = 1; i < n - x + 1; i++) {
        ssum[i] = ssum[i - 1] + arr[i + x - 1] - arr[i - 1];
    }

    int num = *max_element(ssum.begin(), ssum.end());
    if (num == 0) {
        cout << "SAD";
    } else {
        cout << num << '\n';
        cout << count(ssum.begin(), ssum.end(), num);
    }
}