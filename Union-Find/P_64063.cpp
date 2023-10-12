#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<long long, long long> parent;

long long assignRoom(long long node) {
    if (parent[node] == 0) {     // 즉시 방 배정 가능
        parent[node] = node + 1; // 방 배정
        return node;
    }
    return parent[node] = assignRoom(parent[node]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for (int i = 0; i < room_number.size(); i++) {
        long long room = assignRoom(room_number[i]);
        answer.push_back(room);
    }

    return answer;
}