#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> arr;
bool alpha[26];
string alphabet = "bdefghjklmopqrsuvwxyz";
int maxWords = -1;

bool checkAvailable(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (alpha[str[i] - 'a'] == false)
            return false;
    }
    return true;
}

void back(int idx, int cnt, int k) {
    if (cnt == k) { // 다 골랐을 때
        int words = 0;
        for (int i = 0; i < arr.size(); i++) {
            words += checkAvailable(arr[i]);
        }
        if (maxWords < words)
            maxWords = words;
        return;
    }

    for (int i = idx + 1; i < alphabet.size(); i++) { // 순서는 중요하지 않음
        if (!alpha[alphabet[i] - 'a']) {
            alpha[alphabet[i] - 'a'] = true;
            back(i, cnt + 1, k);
            alpha[alphabet[i] - 'a'] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    alpha[0] = alpha['n' - 'a'] = alpha['t' - 'a'] = alpha['i' - 'a'] = alpha['c' - 'a'] = true;
    int n, k;
    cin >> n >> k;
    k -= 5;
    if (k < 0) {
        cout << 0;
        return 0;
    }

    arr.assign(n, "");
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] = arr[i].substr(4, arr[i].size() - 8); // 시작 인덱스, 개수
    }

    back(-1, 0, k);
    cout << maxWords;
}