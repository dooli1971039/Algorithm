#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

/**
 * map으로 <번호, 추천 횟수>를 저장
 */

bool cmp(const pair<int, pair<int, int>> &c1, const pair<int, pair<int, int>> &c2) {
    if (c1.second.first == c2.second.first) { // 추천횟수가 같으면
        return c1.second.second < c2.second.second;
    }
    return c1.second.first < c2.second.first;
}

int main() {
    int n, stu; // 사진틀, 학생 수
    cin >> n >> stu;

    map<int, pair<int, int>> mp; // 학생 번호, 추천 횟수

    for (int i = 0; i < stu; i++) {
        int num;
        cin >> num;

        if (mp.size() == n && mp.count(num) == 0) {
            // 삭제
            mp.erase(min_element(mp.begin(), mp.end(), cmp));
        }

        if (mp.count(num) == 0) { // 새로 추가
            mp[num].second = i;
        }

        mp[num].first++;
    }

    for (auto m : mp) {
        cout << m.first << " ";
    }
}