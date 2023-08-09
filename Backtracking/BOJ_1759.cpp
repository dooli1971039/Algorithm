#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int L, C;

char arr[15];
vector<char> result;

bool checkVowel(char ch) {
    switch (ch) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

bool checkValidation() {
    int vowel = 0, consonant = 0;
    for (auto ch : result) {
        if (checkVowel(ch)) {
            vowel++;
        } else {
            consonant++;
        }
    }

    return (vowel >= 1 && consonant >= 2);
}

void secretCode(int num, int idx) {
    if (num == L) {
        if (!checkValidation()) // 자음모음 개수 체크
            return;

        // 출력
        for (auto ch : result)
            cout << ch;
        cout << "\n";
        return;
    }

    for (int i = idx + 1; i < C; i++) {
        result[num] = arr[i];
        secretCode(num + 1, i);
    }
}

int main() {
    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + C);
    result.assign(L, ' ');
    secretCode(0, -1);
}