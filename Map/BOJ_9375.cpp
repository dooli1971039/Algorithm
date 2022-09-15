#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;

    while (test--) {
        int n;
        cin >> n;

        map<string, int> mp;
        string name, clothes;

        while (n--) {
            cin >> name >> clothes;
            mp[clothes]++;
        }

        int answer = 1;
        for (auto iter = mp.begin(); iter != mp.end(); iter++)
            // answer *= ((*iter).second + 1);
            answer *= (iter->second + 1);

        cout << answer - 1 << '\n';
    }
}
