#include <iostream>
#include <vector>

using namespace std;

int calcRow(int h, vector<int> &arr) {
    vector<int> row;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= h) {
            row.push_back(i);
        }
    }

    if (row.size() <= 1 || row.size() == arr.size()) {
        return 0;
    }

    int result = 0;
    for (int i = 0; i < row.size() - 1; i++) {
        result += (row[i + 1] - row[i] - 1);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int w, h;
    cin >> h >> w;
    vector<int> wall(w);
    for (int i = 0; i < w; i++)
        cin >> wall[i];

    int result = 0;
    while (h) {
        result += calcRow(h, wall); // 위에서부터 계산
        h--;
    }

    cout << result;
}