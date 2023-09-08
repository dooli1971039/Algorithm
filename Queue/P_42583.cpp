#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q;
    for (int i = 0; i < bridge_length; i++) {
        q.push(0);
    }

    int time = 0;
    int ssum = 0;
    for (int i = 0; i < truck_weights.size(); i++) {
        int out = q.front();
        ssum -= out;
        q.pop();

        if (ssum + truck_weights[i] <= weight) {
            q.push(truck_weights[i]);
            ssum += truck_weights[i];
        } else {
            q.push(0);
            i--;
        }
        time++; // 시간은 매번 감
    }

    time += q.size();
    return time;
}