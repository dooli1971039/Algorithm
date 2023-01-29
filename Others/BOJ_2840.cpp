#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, char> ci;

/*
    - 배열을 ?로 초기화 해주고, 입력한대로 처리한다
    - 바퀴를 배열로 보고, 바퀴를 가리키는 화살표를 인덱스로 본다면, 화살표는 배열의 왼쪽 방향으로 이동한다.

    <주의 사항>
    1. ?이 아닌 문자가 저장되어있는데, 다른 문자를 저장하려는 경우
    2. 룰렛에 중복되는 문자가 있는 경우
*/

// 특정 화살표에서 시작한 행운의 바퀴 리턴
string arrowStartWheel(int index, int n, vector<char> &wheel) {
    string ans = "";

    for (int i = 0; i < n; i++) {
        ans += wheel[(i + index) % n];
    }

    return ans;
}

string makeWheel(int n, vector<ci> &record) {
    vector<char> wheel(n, '?');           //?로 초기화
    vector<bool> is_available(26, false); // 알파벳 중복 체크

    int index = 0; // 화살표가 가리키는 인덱스

    for (int i = 0; i < record.size(); i++) {
        int rot = record[i].first;
        int ch = record[i].second;

        index = index - rot;
        if (index < 0) { // 음수일 경우에 +n 해서 인덱스를 조정(원판이니까)
            index += n;
        }

        if (wheel[index] == ch) {
            continue;
        }

        // 주의사항 체크
        // 원판의 해당 위치에 다른 문자가 저장되어있거나, 이미 다른 곳에 문자가 사용된 경우
        if (wheel[index] != '?' || is_available[ch - 'A']) {
            return "!";
        }

        wheel[index] = ch;             // 원판에 기록
        is_available[ch - 'A'] = true; // 알파벳 사용을 표시
    }

    return arrowStartWheel(index, n, wheel);
}

int main() {
    // 입력
    int n, k;
    cin >> n >> k;

    vector<ci> record(k, {0, 0}); // 바퀴 회전 기록
    for (int i = 0; i < k; i++) {
        cin >> record[i].first >> record[i].second;
    }

    // 출력
    cout << makeWheel(n, record);
}