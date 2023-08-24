#include <queue>
#include <string>
#include <vector>

using namespace std;

int n;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

vector<vector<bool>> makePuzzleArr(vector<pair<int, int>> &puzzle) {
    int minR = 100, minC = 100, maxR = -1, maxC = -1;
    for (int i = 0; i < puzzle.size(); i++) {
        minR = min(minR, puzzle[i].first);
        maxR = max(maxR, puzzle[i].first);

        minC = min(minC, puzzle[i].second);
        maxC = max(maxC, puzzle[i].second);
    }

    int rowSize = maxR - minR + 1;
    int colSize = maxC - minC + 1;

    vector<vector<bool>> result(rowSize, vector<bool>(colSize, false));

    for (int i = 0; i < puzzle.size(); i++) {
        int nr = puzzle[i].first - minR;
        int nc = puzzle[i].second - minC;

        result[nr][nc] = true;
    }

    return result;
}

vector<vector<vector<bool>>> extractSpace(vector<vector<int>> &arr, int spaceType) {
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vector<vector<vector<bool>>> result;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != spaceType || vis[i][j])
                continue;

            q.push({i, j}); // 추가
            vis[i][j] = true;

            vector<pair<int, int>> puzzle;
            puzzle.push_back({i, j});

            while (!q.empty()) {
                auto point = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = dr[k] + point.first;
                    int nc = dc[k] + point.second;

                    if (nr >= 0 && nc >= 0 && nr < n && nc < n && arr[nr][nc] == spaceType && vis[nr][nc] == 0) {
                        // 여기서 추가
                        q.push({nr, nc});
                        vis[nr][nc] = true;
                        puzzle.push_back({nr, nc});
                    }
                }
            }

            // 퍼즐을 직사각형에 최대한 맞추어 저장
            auto puzzle_result = makePuzzleArr(puzzle);
            result.push_back(puzzle_result);
        }
    }

    return result;
}

// 배열의 크기를 return
int calcArrSize(vector<vector<bool>> &arr) {
    int rowSize = arr.size();
    int colSize = arr[0].size();

    return rowSize * colSize;
}

bool compareArr(vector<vector<bool>> &board, vector<vector<bool>> &table) {
    int rowSize = board.size();
    int colSize = board[0].size();

    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (board[i][j] != table[i][j])
                return false;
        }
    }

    return true;
}

vector<vector<bool>> rotatePuzzle(vector<vector<bool>> &arr) {
    int rowSize = arr.size();    // 원래의 행 (세로 길이)
    int colSize = arr[0].size(); // 원래의 열 (가로 길이)

    vector<vector<bool>> result;

    for (int i = 0; i < colSize; i++) { // 원래의 열
        vector<bool> makeRow;
        for (int j = rowSize - 1; j >= 0; j--) { // 원래의 행
            makeRow.push_back(arr[j][i]);
        }
        result.push_back(makeRow);
    }

    return result;
}

int calcPuzzleSize(vector<vector<bool>> &arr) {

    int num = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            if (arr[i][j])
                num++;
        }
    }

    return num;
}

int comparePuzzle(vector<vector<bool>> &board, vector<vector<bool>> &table) {
    // board는 가만히 두고, table만 바꿈
    bool result = false;

    for (int i = 0; i < 4; i++) {
        if (board.size() != table.size() || board[0].size() != table[0].size()) {
            // 테이블 회전
            table = rotatePuzzle(table);
            continue;
        }

        result = compareArr(board, table);
        if (result)
            return calcPuzzleSize(table);
        else {
            // 테이블 회전
            table = rotatePuzzle(table);
        }
    }
    return 0;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    n = game_board.size();

    auto boardPuzzle = extractSpace(game_board, 0);
    auto tablePuzzle = extractSpace(table, 1);

    int answer = 0;

    vector<bool> boardUsed(boardPuzzle.size(), false);
    vector<bool> tableUsed(tablePuzzle.size(), false);

    for (int i = 0; i < boardPuzzle.size(); i++) {
        for (int j = 0; j < tablePuzzle.size(); j++) {
            if (calcArrSize(boardPuzzle[i]) != calcArrSize(tablePuzzle[j]) || boardUsed[i] || tableUsed[j])
                continue;

            int num = comparePuzzle(boardPuzzle[i], tablePuzzle[j]);
            if (num > 0) {
                answer += num;
                boardUsed[i] = true;
                tableUsed[j] = true;
            }
        }
    }

    return answer;
}