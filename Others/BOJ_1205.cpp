#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, p;
    long long score;
    cin >> n >> score >> p;

    if (n == 0) {
        cout << 1;
        return 0;
    }

    vector<long long> arr(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    if (n == p && arr[arr.size() - 1] >= score) {
        cout << -1;
        return 0;
    }

    int rank = n + 1;
    for (int i = 1; i <= n; i++) {

        if (score >= arr[i]) {
            rank = i;
            break;
        }
    }

    cout << rank;
}