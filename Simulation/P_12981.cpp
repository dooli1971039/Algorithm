#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    set<string> usedWords;

    string lastWord = words[0];
    usedWords.insert(lastWord);

    for (int i = 1; i < words.size(); i++) {
        // 이전 글자의 마지막으로 시작하지 않거나 이미 사용된 글자인 경우 탈락
        if (lastWord[lastWord.size() - 1] != words[i][0] || usedWords.count(words[i]) != 0) {
            answer[0] = i % n + 1; // 사람 번호
            answer[1] = i / n + 1; // 몇회차에 탈락하는지
            return answer;
        }
        lastWord = words[i];
        usedWords.insert(lastWord);
    }

    return answer;
}