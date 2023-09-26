#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> origin(n, 0);
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        origin[i] = arr[i];
    }

    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for (int i = 0; i < n; i++) {
        cout << lower_bound(arr.begin(), arr.end(), origin[i]) - arr.begin() << ' ';
    }
}