#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
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

        cout << binary_search(arr.begin(), arr.end(), tmp) << '\n';
    }
}