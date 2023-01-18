#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    double ssum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ssum += arr[i];
    }

    sort(arr.begin(), arr.end());
    ssum = ssum / arr[n - 1] * 100;
    cout << ssum / n;
}
