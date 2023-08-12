#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<string, vector<string>> team_member; // 팀, 멤버 벡터
    unordered_map<string, string> member_team;         // 멤버, 팀

    string team, member;
    int member_num;
    while (n--) {
        cin >> team >> member_num;
        vector<string> member_list; // 해당 팀에 속하는 멤버 벡터
        while (member_num--) {
            cin >> member;
            member_list.push_back(member);
            member_team[member] = team;
        }
        sort(member_list.begin(), member_list.end()); // 멤버는 사전순으로 정렬
        team_member[team] = member_list;
    }

    int question_type;
    string question;
    while (m--) {
        cin >> question >> question_type;
        if (question_type == 0) { // 팀을 입력 받아 멤버들을 출력
            for (auto member : team_member[question]) {
                cout << member << "\n";
            }
        } else { // 멤버를 입력 받아 팀을 출력
            cout << member_team[question] << "\n";
        }
    }
}