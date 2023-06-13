#include <iostream>
#include <vector>
using namespace std;

void solution() {
    int n;
    cin >> n;
    vector<int> arr;

    while (n) {
        arr.push_back(n % 2);
        n /= 2;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i]) {
            cout << i << ' ';
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}