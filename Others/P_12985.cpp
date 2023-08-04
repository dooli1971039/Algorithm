#include <iostream>

using namespace std;

int returnTeamNumber(int num, int pow) {
    if (num % pow == 0)
        return num / pow - 1;
    else
        return num / pow;
}

int solution(int n, int a, int b) {
    int pow = 1;
    for (int round = 1; round <= 20; round++) {
        pow *= 2;

        if (returnTeamNumber(a, pow) == returnTeamNumber(b, pow)) {
            return round;
        }
    }
}