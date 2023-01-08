#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    if (arr.size() == 1)
        cout << arr[0] << ' ' << arr[0];
    else
        cout << arr[0] << ' ' << arr[arr.size() - 1];
}
