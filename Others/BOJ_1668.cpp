#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int cntL = 1, cntR = 1;
    int temp = arr[0];
    for (int i = 1; i < n; i++) {
        if (temp < arr[i]) {
            temp = arr[i];
            cntL++;
        }
    }

    temp = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (temp < arr[i]) {
            temp = arr[i];
            cntR++;
        }
    }
    cout << cntL << '\n' << cntR;
}