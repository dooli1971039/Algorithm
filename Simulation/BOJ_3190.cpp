#include <deque>
#include <iostream>
#include <vector>

using namespace std;

// 우, 하, 좌, 상
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n, k;
    cin >> n >> k; // 보드의 크기, 사과의 위치

    int arr[n + 1][n + 1] = {
        0,
    };
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1; // 사과
    }

    int dcnt;
    cin >> dcnt;
    vector<pair<int, char>> info;
    for (int i = 0; i < dcnt; i++) {
        int t;
        char dir;
        cin >> t >> dir;
        info.push_back(make_pair(t, dir));
    }

    // solution
    int time = 0;
    int info_idx = 0;
    int dir_idx = 0;

    deque<pair<int, int>> bam;
    bam.push_front({1, 1});
    arr[1][1] = -1; // 뱀 위치
    while (true) {
        time++;

        //  머리를 다음칸에 위치시킨다.
        int ny = bam.front().first + dy[dir_idx];
        int nx = bam.front().second + dx[dir_idx];

        if (nx <= 0 || ny <= 0 || nx > n || ny > n || arr[ny][nx] == -1) { // 몸 or 벽에 부딪힘
            cout << time;
            return 0;
        } else if (arr[ny][nx] == 1) { // 사과가 있으면 추가만
            arr[ny][nx] = -1;
            bam.push_front({ny, nx});
        } else { // 아무것도 아니면 추가 후 꼬리 삭제
            arr[ny][nx] = -1;
            bam.push_front({ny, nx});

            // 꼬리 삭제
            arr[bam.back().first][bam.back().second] = 0;
            bam.pop_back();
        }

        // 방향을 바꿔야함
        if (info_idx < dcnt && time == info[info_idx].first) {
            if (info[info_idx].second == 'D') {
                dir_idx = (dir_idx + 1) % 4;
            } else if (info[info_idx].second == 'L') {
                dir_idx = (dir_idx + 4 - 1) % 4;
            }
            info_idx++;
        }
    }
}