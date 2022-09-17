#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, int> order; //순서 저장

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) // 같은 빈도이면 순서 유지
        return order[a.first] < order[b.first];
    else
        return a.second > b.second; //빈도가 다르면 큰것부터
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    map<int, int> mp;

    cin >> n >> c;

    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        mp[tmp]++; // {tmp, 입력개수}

        if (order[tmp] == 0)
            order[tmp] = i + 1; //순서 저장 (여기를 그냥 i로 하면 안됨)
    }

    // map의 정렬조건을 바꾸려면 일단 vector로 바꿔야 함
    vector<pair<int, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++) {
        while (v[i].second--)
            cout << v[i].first << ' ';
    }
}
