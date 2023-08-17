#include <queue>
#include <string>
#include <vector>

using namespace std;

// 102로 여유있게 선언하여, bfs 탐색 시 좌표 범위 체크를 안 하도록 함
// 어차피 테두리 아닌 부분과 마찬가지로 false 세팅 됨
// 101로 세팅했다가, 101f라인에 테두리가 있으면 범위 체크가 필요하다.
bool arr[102][102];
int visited[102][102];

int dy[4] = {0, 0, 1, -1};
int dx[4] = {-1, 1, 0, 0};

void initArrWithRectangleLine(vector<int> &rectangle) {
    int lx = rectangle[0] * 2; // bfs에서 걸리지 않게 2배로 해서 넣음
    int ly = rectangle[1] * 2;
    int rx = rectangle[2] * 2;
    int ry = rectangle[3] * 2;

    for (int i = lx; i <= rx; i++) {
        arr[ly][i] = true;
        arr[ry][i] = true;
    }
    for (int i = ly; i <= ry; i++) {
        arr[i][lx] = true;
        arr[i][rx] = true;
    }
}

void initArrWithRectangleBlank(vector<int> &rectangle) {
    int lx = rectangle[0] * 2;
    int ly = rectangle[1] * 2;
    int rx = rectangle[2] * 2;
    int ry = rectangle[3] * 2;

    // 사각형의 내부는 전부 false 세팅
    for (int i = ly + 1; i < ry; i++) {
        for (int j = lx + 1; j < rx; j++) {
            arr[i][j] = false;
        }
    }
}

void initArrWithRectangles(vector<vector<int>> &rectangles) {
    for (auto rectangle : rectangles) // 사각형들 테두리 그리기
        initArrWithRectangleLine(rectangle);
    for (auto rectangle : rectangles) // 사각형들 내부의 테두리 지우기
        initArrWithRectangleBlank(rectangle);
}

int solution(vector<vector<int>> rectangles, int characterX, int characterY, int itemX, int itemY) {
    initArrWithRectangles(rectangles);
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;

    queue<pair<int, int>> q;
    q.push({characterY, characterX});    // 주의!! Y가 행이다.
    visited[characterY][characterX] = 1; // 1로 시작하니 나중에 -1 해야 함

    while (!q.empty()) {
        auto point = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = point.first + dy[i];
            int nx = point.second + dx[i];

            if (arr[ny][nx] && visited[ny][nx] == 0) { // 테두리이고, 아직 방문하지 않았을 때
                q.push({ny, nx});
                visited[ny][nx] = visited[point.first][point.second] + 1;
            }
        }
    }

    return (visited[itemY][itemX] - 1) / 2;
}