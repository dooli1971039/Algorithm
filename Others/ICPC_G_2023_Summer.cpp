#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; // 문제 개수
    cin >> n;

    vector<int> arr(6, 0); // 난이도별로 풀어야하는 문제 개수
    for (int i = 1; i <= 5; i++) {
        cin >> arr[i];
    }

    int time = 240; // 난이도 넘어가는 시간 (난이도별로 1문제씩은 푼다)

    vector<int> minutes[6];
    int level, min;
    for (int i = 0; i < n; i++) {
        cin >> level >> min;
        minutes[level].push_back(min);
    }

    for (int i = 1; i <= 5; i++) { // 난이도별로 시간 계산
        sort(minutes[i].begin(), minutes[i].end());
        int ssum = minutes[i][0]; // 가장 시간 적은거
        for (int j = 1; j < arr[i]; j++) {
            ssum += (minutes[i][j] - minutes[i][j - 1]);
            ssum += minutes[i][j];
        }
        time += ssum;
    }
    cout << time;
}