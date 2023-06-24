#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n, {0, 0});
    pair<int, int> mmax = {0, 0};

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        if (mmax.second < arr[i].second) {
            mmax.second = arr[i].second;
            mmax.first = arr[i].first;
        }
    }

    sort(arr.begin(), arr.end());
    int result = 0;
    pair<int, int> left = arr[0];
    for (int i = 0; i < n; i++) {
        if (left.second < arr[i].second) {
            result += (left.second * (arr[i].first - left.first));
            left = arr[i];
        }
    }

    pair<int, int> right = arr[arr.size() - 1];
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (right.second <= arr[i].second) {
            result += (right.second * (right.first - arr[i].first));
            right = arr[i];
        }
    }

    cout << result + right.second;
}