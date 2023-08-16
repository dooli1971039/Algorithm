#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[51][51]; // 0 빈칸, 1 집, 2 치킨
vector<pair<int, int>> house;
vector<pair<int, int>> originChicken;
vector<pair<int, int>> resultChicken;
int resultMin = 1e5;

// houseNum번째 집과 chickenNum번째 치킨집 사이의 거리 반환
int calcDistanceHouseAndChicken(int houseNum, int chickenNum) {
    int hr = house[houseNum].first;
    int hc = house[houseNum].second;
    int cr = resultChicken[chickenNum].first;
    int cc = resultChicken[chickenNum].second;

    return abs(hr - cr) + abs(hc - cc);
}

// 도시의 치킨 거리 구하기
int calcDistanceOfCity() {
    int ssum = 0;
    for (int i = 0; i < house.size(); i++) {
        int mmin = 1e5;
        for (int j = 0; j < resultChicken.size(); j++) {
            mmin = min(mmin, calcDistanceHouseAndChicken(i, j));
        }
        ssum += mmin;
    }
    return ssum;
}

void chooseChicken(int cnt, int cur) { // 중복 없이. 순서 상관 X (그래서 그냥 오름차순으로 함)
    if (cnt == m) {
        // 도시의 치킨 거리 계산 후 최솟값 업데이트
        resultMin = min(resultMin, calcDistanceOfCity());
        return;
    }

    for (int i = cur; i < originChicken.size(); i++) {
        resultChicken[cnt] = originChicken[i];
        chooseChicken(cnt + 1, i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                house.push_back({i, j});
            } else if (arr[i][j] == 2) {
                originChicken.push_back({i, j});
            }
        }
    }

    resultChicken.assign(m, {0, 0});
    chooseChicken(0, 0);

    cout << resultMin;
}