#include <iostream>
#include <vector>
using namespace std;

int arr[5][5];
bool bingo[5][5];

bool checkRow(int row) {
    for (int i = 0; i < 5; i++) {
        if (bingo[row][i] == false)
            return false;
    }
    return true;
}

bool checkCol(int col) {
    for (int i = 0; i < 5; i++) {
        if (bingo[i][col] == false)
            return false;
    }
    return true;
}

int checkDig() {
    int up = 1;
    int down = 1;
    for (int i = 0; i < 5; i++) {
        if (bingo[i][i] == false)
            down = 0;
        if (bingo[i][5 - i - 1] == false)
            up = 0;
    }

    return up + down;
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    int tmp;
    int cnt = 0;
    for (int i = 0; i < 25; i++) {
        cin >> tmp;
        cnt++;

        // 위치를 찾아서 표시
        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 5; y++) {
                if (arr[x][y] == tmp) {
                    bingo[x][y] = true;
                }
            }
        }

        // 빙고 체크
        int check = 0;
        for (int i = 0; i < 5; i++) {
            check += checkRow(i);
            check += checkCol(i);
        }
        check += checkDig();

        if (check >= 3) {
            cout << cnt;
            return 0;
        }
    }
}