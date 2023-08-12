#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool isBeforeAB(string A, string B) {
    int hourA = stoi(A.substr(0, 2));
    int hourB = stoi(B.substr(0, 2));

    if (hourA < hourB) {
        return true;
    } else if (hourA == hourB) {
        int minuteA = stoi(A.substr(3, 2));
        int minuteB = stoi(B.substr(3, 2));

        if (minuteA < minuteB)
            return true;
        else
            return false;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S, E, Q;
    cin >> S >> E >> Q;
    string time, name;

    unordered_set<string> attendance;
    unordered_set<string> result;

    while (true) {
        cin >> time >> name;

        if (isBeforeAB(time, S) || time == S) { // 개강총회 시작 시간 전까지
            attendance.insert(name);
        } else if (!isBeforeAB(time, E)) {          // 개강총회 끝난 시간부터
            if (isBeforeAB(time, Q) || time == Q) { // 스밍 끝난 시간까지
                if (attendance.count(name) != 0) {
                    result.insert(name);
                }
            }
        }

        if (cin.eof()) {
            cout << result.size();
            break;
        }
    }
}