#include <string>
#include <vector>

using namespace std;

int calcGCD(int a, int b) { // 반드시 a가 더 크게 입력할 것
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int calcLCM(int a, int b) {
    if (a < b)
        swap(a, b);
    return a / calcGCD(a, b) * b;
}

int solution(vector<int> arr) {
    int num = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        num = calcLCM(num, arr[i]);
    }

    return num;
}