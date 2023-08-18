/* PCCP 모의고사 2회 3번
 * https://school.programmers.co.kr/learn/courses/15009/lessons/121689
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> menu, vector<int> order, int k) {
    vector<int> menu_time; // 각각의 메뉴가 얼마나 걸리는지
    int ssum = 0;
    for (int i = 0; i < order.size(); i++) {
        menu_time.push_back(menu[order[i]]);
        ssum += menu_time[i];
    }

    int people = 0;
    int idx = 0;
    int prevOutTime = 0;
    int mmax = -1;
    for (int i = 0; i < ssum; i++) {
        // 나가는게 먼저
        if (prevOutTime + menu_time[idx] == i) {
            people--;
            prevOutTime = i;
            idx++;
        }

        // 들어오는게 나중
        if (i % k == 0 && i / k < order.size()) {
            people++;
            if (k * idx > prevOutTime)
                prevOutTime = i;
        }
        mmax = max(mmax, people);
    }

    return mmax;
}