#include <iostream>
#include <vector>

using namespace std;

int sorting(vector<int> &arr) {
    int cnt = 0;

    int idx = arr.size() - 1;
    while (idx != 0) {
        if (arr[idx] < arr[idx - 1]) {
            int tmp = arr[idx];
            arr[idx] = arr[idx - 1];
            arr[idx - 1] = tmp;
            idx--;
            cnt++;
        } else {
            return cnt;
        }
    }
    return cnt;
}

void solution() {
    vector<int> arr;
    int cnt = 0;
    int step;
    cin >> step;
    cout << step;
    for (int i = 0; i < 20; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
        cnt += sorting(arr);
    }
    cout << " " << cnt << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}