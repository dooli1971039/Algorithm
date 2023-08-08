#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n;
int arr[401][4] = {
    0,
};
int seat[21][21] = {
    0,
};

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

/* student가 seatStudent를 좋아하는지 체크
 * student가 좋아하는 친구 목록에 seatStudent가 있는지 확인할 것
 */
bool isLikeStudent(int student, int seatStudent) {
    for (int i = 0; i < 4; i++) {
        if (arr[student][i] == seatStudent)
            return true;
    }
    return false;
}

// 특정 칸(r,c)을 기준으로 상하좌우를 탐색하여, student가 좋아하는 사람 수 구하기
int returnLikeFriend(int r, int c, int student) {
    int friendCnt = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 1 && nr <= n && nc >= 1 && nc <= n) {
            if (isLikeStudent(student, seat[nr][nc])) {
                friendCnt++;
            }
        }
    }
    return friendCnt;
}

// 특정 칸(r,c)을 기준으로 상하좌우를 탐색하여, 공백 개수 구하기
int returnBlank(int r, int c) {
    int blank = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 1 && nr <= n && nc >= 1 && nc <= n) {
            if (seat[nr][nc] == 0)
                blank++;
        }
    }
    return blank;
}

// 자리 결정
void decideSeat(int student) {
    // 만족도가 최대인 자리 구하기
    int seat_like = -1;
    vector<pair<int, int>> like_list; // 만족도가 최대인 위치들 리스트

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (seat[i][j] == 0) {
                int like_cnt = returnLikeFriend(i, j, student);
                if (like_cnt > seat_like) { // 만족도 갱신
                    like_list.clear();
                    like_list.push_back({i, j});
                    seat_like = like_cnt;
                } else if (like_cnt == seat_like) { // 만족도 리스트에 추가
                    like_list.push_back({i, j});
                }
            }
        }
    }

    // 공백 최대인 곳 구하기
    int seat_blank = -1;
    vector<pair<int, int>> blank_list; // 공백 최대인 곳들 리스트

    for (int i = 0; i < like_list.size(); i++) {
        int blank_cnt = returnBlank(like_list[i].first, like_list[i].second);
        if (blank_cnt > seat_blank) {
            blank_list.clear();
            blank_list.push_back(like_list[i]);
            seat_blank = blank_cnt;
        } else if (blank_cnt == seat_blank) {
            blank_list.push_back(like_list[i]);
        }
    }

    // sort함수: 첫번째 인자(행) 기준으로 정렬 후, 같은 경우 두번째 인자(열) 기준으로 정렬
    sort(blank_list.begin(), blank_list.end());
    pair<int, int> seat_result = blank_list[0];
    seat[seat_result.first][seat_result.second] = student;
    return;
}

// (r,c)위치의 학생 만족도 구하기
int calcLikeScore(int r, int c) {
    int cnt = returnLikeFriend(r, c, seat[r][c]);

    switch (cnt) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 10;
    case 3:
        return 100;
    default:
        return 1000;
    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    int student;
    for (int i = 1; i <= n * n; i++) {
        cin >> student;
        for (int i = 0; i < 4; i++) { // student 학생의 좋아하는 친구 저장
            cin >> arr[student][i];
        }

        decideSeat(student);
    }

    // 모든 학생의 만족도 계산
    int like_score = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            like_score += calcLikeScore(i, j);
        }
    }
    cout << like_score;
}