#include <string>
#include <vector>

using namespace std;

int zeroCnt = 0;
int oneCnt = 0;

void splitArr(int r, int c, int len, vector<vector<int>> &arr) {
    if (len == 1) {
        if (arr[r][c])
            oneCnt++;
        else
            zeroCnt++;
        return;
    }

    int num = arr[r][c];
    bool check = true;
    for (int i = r; i < r + len; i++) {
        for (int j = c; j < c + len; j++) {
            if (num != arr[i][j]) {
                len /= 2;
                splitArr(r, c, len, arr);
                splitArr(r + len, c, len, arr);
                splitArr(r, c + len, len, arr);
                splitArr(r + len, c + len, len, arr);
                return;
            }
        }
    }

    if (num)
        oneCnt++;
    else
        zeroCnt++;
    return;
}

vector<int> solution(vector<vector<int>> arr) {
    splitArr(0, 0, arr.size(), arr);
    vector<int> answer = {zeroCnt, oneCnt};
    return answer;
}