#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    int m, tmp;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> tmp;

        cout << upper_bound(arr.begin(), arr.end(), tmp) - lower_bound(arr.begin(), arr.end(), tmp) << ' ';
    }
}