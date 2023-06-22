#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 우 하 좌 상
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

vector<int> arr; // min_x, max_x, min_y, max_x

void calcMinMax(int xx, int yy) {
    arr[0] = min(arr[0], xx);
    arr[1] = max(arr[1], xx);
    arr[2] = min(arr[2], yy);
    arr[3] = max(arr[3], yy);
}

int calcRect() { return (arr[1] - arr[0]) * (arr[3] - arr[2]); }

int solution(string str) {
    int x = 0, y = 0;
    int dir = 3;
    arr.assign(4, 0);

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'F' || str[i] == 'B') {
            int mul = str[i] == 'F' ? 1 : -1;

            x = mul * dx[dir] + x;
            y = mul * dy[dir] + y;

            // 최소,최대값 갱신하기
            calcMinMax(x, y);
        } else if (str[i] == 'L') {
            dir = (dir + 4 - 1) % 4;
        } else if (str[i] == 'R') {
            dir = (dir + 1) % 4;
        }
    }

    // 넓이 계산
    return calcRect();
}

int main() {
    int testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; i++) {
        string str;
        cin >> str;
        cout << solution(str) << "\n";
    }
}