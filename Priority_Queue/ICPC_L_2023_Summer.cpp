#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<int> arr[12]; // 1~11번

    int p, w;
    for (int i = 0; i < n; i++) {
        cin >> p >> w;
        arr[p].push(w);
    }

    while (k--) {
        for (int i = 1; i <= 11; i++) {

            if (arr[i].empty())
                continue;
            else if (arr[i].top() == 0)
                continue;
            else {
                int num = arr[i].top();
                arr[i].pop();
                arr[i].push(--num);
            }
        }
    }

    int ssum = 0;
    for (int i = 1; i <= 11; i++) {
        if (arr[i].empty())
            continue;
        ssum += arr[i].top();
    }

    cout << ssum;
}