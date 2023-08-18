/* PCCP 모의고사 2회 1번
 * https://school.programmers.co.kr/learn/courses/15008/lessons/121685
 */

#include <string>
#include <vector>

using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

vector<int> solution(string command) {
    int dir = 0;
    int y = 0;
    int x = 0;

    for (int i = 0; i < command.size(); i++) {
        if (command[i] == 'R') {
            dir = (dir + 1) % 4;
        } else if (command[i] == 'L') {
            dir = (dir - 1 + 4) % 4;
        } else if (command[i] == 'G') {
            y += dy[dir];
            x += dx[dir];
        } else {
            y -= dy[dir];
            x -= dx[dir];
        }
    }

    vector<int> answer = {x, y};
    return answer;
}