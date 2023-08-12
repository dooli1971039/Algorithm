#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k, L;
    cin >> k >> L;

    // 학번이 int면 00000000이 0으로 저장된다.
    unordered_map<string, int> waiting_list; // 학번, 순서
    int cnt = 0;
    string studentId;
    while (L--) {
        cin >> studentId;

        waiting_list[studentId] = cnt;
        cnt++;
    }

    // 순서를 기준으로 정렬 후
    vector<pair<int, string>> result_list; // 순서, 학번
    for (auto student : waiting_list) {
        result_list.push_back({student.second, student.first}); // 순서, 학번
    }
    sort(result_list.begin(), result_list.end());

    // 수강신청 순서대로 출력
    for (int i = 0; i < k && i < result_list.size(); i++) {
        cout << result_list[i].second << "\n";
    }
}