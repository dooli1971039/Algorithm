#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solution(int n, int m, vector<int> &arr) {
    sort(arr.begin(), arr.end());

    int st = 0;
    int ed = n - 1;

    int summ = 0;
    int cnt = 0;
    while (st < ed) {
        summ = arr[st] + arr[ed];

        if (summ == m) {
            cnt++;
            st++;
            ed--;
        } else if (summ < m) {
            st++;
        } else {
            ed--;
        }
    }
    cout << cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    solution(n, m, arr);
}