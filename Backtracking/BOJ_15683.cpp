#include <iostream>
#include <vector>
using namespace std;

struct CCTV {
    int r;
    int c;
    int cctvType;  // 1~5
    int direction; // 0~3: 오른쪽, 아래, 왼쪽, 위
};

int n;
int m;
vector<vector<int>> arr;
vector<vector<int>> newArr;
vector<CCTV> originCCTV;
vector<CCTV> resultCCTV;
int mmin = 100;

void drawLeft(int r, int c) {
    for (int i = c - 1; i >= 1; i--) {
        if (newArr[r][i] == 6) {
            return;
        } else if (newArr[r][i] == 0) {
            newArr[r][i] = -1; // #
        }
    }
}

void drawDown(int r, int c) {
    for (int i = r + 1; i <= n; i++) {
        if (newArr[i][c] == 6) {
            return;
        } else if (newArr[i][c] == 0) {
            newArr[i][c] = -1; // #
        }
    }
}

void drawRight(int r, int c) {
    for (int i = c + 1; i <= m; i++) {
        if (newArr[r][i] == 6) {
            return;
        } else if (newArr[r][i] == 0) {
            newArr[r][i] = -1; // #
        }
    }
}

void drawUp(int r, int c) {
    for (int i = r - 1; i >= 1; i--) {
        if (newArr[i][c] == 6) {
            return;
        } else if (newArr[i][c] == 0) {
            newArr[i][c] = -1; // #
        }
    }
}

void drawCCTVRange(CCTV cctv) {
    int r = cctv.r;
    int c = cctv.c;

    if (cctv.cctvType == 1) {
        switch (cctv.direction) {
        case 0:
            drawRight(r, c);
            break;
        case 1:
            drawDown(r, c);
            break;
        case 2:
            drawLeft(r, c);
            break;
        case 3:
            drawUp(r, c);
            break;
        default:
            break;
        }
    } else if (cctv.cctvType == 2) {
        switch (cctv.direction) {
        case 0:
            drawRight(r, c);
            drawLeft(r, c);
            break;
        case 1:
            drawDown(r, c);
            drawUp(r, c);
            break;
        default:
            break;
        }
    } else if (cctv.cctvType == 3) {
        switch (cctv.direction) {
        case 0:
            drawUp(r, c);
            drawRight(r, c);
            break;
        case 1:
            drawRight(r, c);
            drawDown(r, c);
            break;
        case 2:
            drawDown(r, c);
            drawLeft(r, c);
            break;
        case 3:
            drawLeft(r, c);
            drawUp(r, c);
            break;
        default:
            break;
        }
    } else if (cctv.cctvType == 4) {
        switch (cctv.direction) {
        case 0:
            drawLeft(r, c);
            drawUp(r, c);
            drawRight(r, c);
            break;
        case 1:
            drawUp(r, c);
            drawRight(r, c);
            drawDown(r, c);
            break;
        case 2:
            drawRight(r, c);
            drawDown(r, c);
            drawLeft(r, c);
            break;
        case 3:
            drawDown(r, c);
            drawLeft(r, c);
            drawUp(r, c);
            break;
        default:
            break;
        }
    } else if (cctv.cctvType == 5) {
        drawDown(r, c);
        drawLeft(r, c);
        drawRight(r, c);
        drawUp(r, c);
    }
}

int calcCCTVRange() {
    newArr.assign(n + 1, vector<int>(m + 1, 0));
    copy(arr.begin(), arr.end(), newArr.begin());

    // 감시 영역 표시하기
    for (int i = 0; i < resultCCTV.size(); i++) {
        drawCCTVRange(resultCCTV[i]);
    }

    // 사각지대 개수 구하기
    int ssum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (newArr[i][j] == 0)
                ssum++;
        }
    }

    return ssum;
}

void decideCCTVDirection(int cnt) {
    if (cnt == originCCTV.size()) {
        mmin = min(mmin, calcCCTVRange());
        return;
    }

    resultCCTV[cnt] = originCCTV[cnt];

    int range;
    if (resultCCTV[cnt].cctvType == 5)
        range = 1;
    else if (resultCCTV[cnt].cctvType == 2)
        range = 2;
    else
        range = 4;

    for (int i = 0; i < range; i++) { // 방향 결정
        resultCCTV[cnt].direction = i;
        decideCCTVDirection(cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    arr.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];

            if (arr[i][j] != 0 && arr[i][j] != 6)
                originCCTV.push_back({i, j, arr[i][j], 0});
        }
    }

    resultCCTV.assign(originCCTV.size(), {0, 0, 0, 0});
    decideCCTVDirection(0);

    cout << mmin;
}