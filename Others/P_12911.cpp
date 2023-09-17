#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string changeToBinaryReverse(int n) {
    string str = "";

    while (n > 0) {
        str += to_string(n % 2);
        n /= 2;
    }
    return str;
}

int countOneInN(int n) {
    string str = changeToBinaryReverse(n);
    int cnt = count(str.begin(), str.end(), '1');
    return cnt;
}

int solution(int n) {
    int baseOne = countOneInN(n);
    int changedNum = n + 1;
    while (true) {
        int changedOne = countOneInN(changedNum);

        if (changedOne == baseOne) {
            return changedNum;
        }
        changedNum++;
    }
}
