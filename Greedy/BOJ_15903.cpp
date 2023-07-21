#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long sumXY = 0;
    while (m--) {
        sort(arr, arr + n);
        sumXY = arr[0] + arr[1];
        arr[0] = arr[1] = sumXY;
    }

    long long sumTotal = 0;
    for (int i = 0; i < n; i++)
        sumTotal += arr[i];
    cout << sumTotal;
}