/* PCCP 모의고사 1회 2번
 * https://school.programmers.co.kr/learn/courses/15008/lessons/121684
 */

#include <string>
#include <vector>

using namespace std;

vector<int> studentOrder;
vector<int> used;
int ex_num;
int student;
int mmax = -1;

void decideStudent(int cnt, vector<vector<int>> &ability) {
    if (cnt == ex_num) {
        // 갱신
        int ssum = 0;
        for (int i = 0; i < cnt; i++) {
            ssum += ability[studentOrder[i]][i];
        }
        mmax = max(mmax, ssum);
        return;
    }

    for (int i = 0; i < student; i++) {
        if (!used[i]) {
            used[i] = true;
            studentOrder[cnt] = i;
            decideStudent(cnt + 1, ability);
            used[i] = false;
        }
    }
}

int solution(vector<vector<int>> ability) {
    ex_num = ability[0].size();
    student = ability.size();

    studentOrder.assign(ex_num, 0);
    used.assign(student, 0);

    decideStudent(0, ability);

    return mmax;
}