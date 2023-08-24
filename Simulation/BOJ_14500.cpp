#include <iostream>
#include <vector>

using namespace std;
int n, m;
int arr[500][500];

vector<vector<vector<bool>>> puzzle = {{{true, true, true, true}},
                                       {{true}, {true}, {true}, {true}},

                                       {{true, true}, {true, true}},

                                       {{true, true, true}, {true, false, false}},
                                       {{false, false, true}, {true, true, true}},
                                       {{true, true}, {false, true}, {false, true}},
                                       {{true, false}, {true, false}, {true, true}},
                                       {{true, false, false}, {true, true, true}},
                                       {{true, true}, {true, false}, {true, false}},
                                       {{false, true}, {false, true}, {true, true}},
                                       {{true, true, true}, {false, false, true}},

                                       {{true, false}, {true, true}, {false, true}},
                                       {{false, true, true}, {true, true, false}},
                                       {{false, true}, {true, true}, {true, false}},
                                       {{true, true, false}, {false, true, true}},

                                       {{true, true, true}, {false, true, false}},
                                       {{false, true, false}, {true, true, true}},
                                       {{true, false}, {true, true}, {true, false}},
                                       {{false, true}, {true, true}, {false, true}}};

int calcSumOfPuzzle(vector<vector<bool>> &puzzle, int r, int c) {
    int ssum = 0;
    for (int i = 0; i < puzzle.size(); i++) {
        for (int j = 0; j < puzzle[0].size(); j++) {
            if (puzzle[i][j]) {
                ssum += arr[r + i][c + j];
            }
        }
    }
    return ssum;
}

int solution() {
    int mmax = -1;
    for (int i = 0; i < puzzle.size(); i++) {
        int rowSize = puzzle[i].size();
        int colSize = puzzle[i][0].size();

        for (int j = 0; j <= n - rowSize; j++) {
            for (int k = 0; k <= m - colSize; k++) {
                mmax = max(mmax, calcSumOfPuzzle(puzzle[i], j, k));
            }
        }
    }
    return mmax;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << solution();
}