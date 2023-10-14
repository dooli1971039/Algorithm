#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, m; // 선물 상자, 학생 수
    cin >> n >> m;

    priority_queue<int> pq; // 선물 상자에 들어있는 선물 개수
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        pq.push(tmp);
    }

    int giftNum;
    int topGiftNum;
    for (int i = 0; i < m; i++) {
        cin >> giftNum;

        topGiftNum = pq.top();
        if (topGiftNum >= giftNum) {
            pq.pop();
            topGiftNum -= giftNum;
            pq.push(topGiftNum);
        } else {
            cout << "0";
            return 0;
        }
    }

    cout << "1";
    return 0;
}