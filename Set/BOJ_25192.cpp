#include <iostream>
#include <set>
// unordered_set의 clear는 시간복잡도가 O(1)이 아님
// set을 써야 한다.
using namespace std;

int main() {
    int n;
    cin >> n;

    string str;
    set<string> ss;
    int answer = 0;
    while (n--) {
        cin >> str;

        if (str == "ENTER") {
            ss.clear();
        } else if (ss.count(str) == 0) {
            ss.insert(str);
            answer++;
        }
    }

    cout << answer;
}