#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(5, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<bool>> check(n, vector<bool>(n, false));

    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i][k] == arr[j][k]) {
                    check[i][j] = true;
                    check[j][i] = true;
                }
            }
        }
    }

    vector<int> ssum(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ssum[i] += check[i][j];
        }
    }

    cout << max_element(ssum.begin(), ssum.end()) - ssum.begin() + 1;
}