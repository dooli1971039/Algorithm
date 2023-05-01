#include <iostream>
#include <vector>
using namespace std;

bool check[2000001];
int main() {
    int n, c;
    cin >> n >> c;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= c; j += arr[i]) {
            check[j] = true;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= c; i++) {
        cnt += check[i] ? 1 : 0;
    }

    cout << cnt;
}