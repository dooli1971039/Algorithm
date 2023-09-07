#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
unordered_set<int> ss;
vector<int> numList;
vector<bool> visited;
vector<int> result;

void backtracking(int cnt, int k) {
    if (cnt == k) {
        int num = 0;
        int ten = 1;
        for (int i = 0; i < k; i++) {
            num += result[i] * ten;
            ten *= 10;
        }
        ss.insert(num);
        return;
    }

    for (int i = 0; i < numList.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            result[cnt] = numList[i];
            backtracking(cnt + 1, k);
            visited[i] = false;
        }
    }
}

vector<bool> isPrime() {
    vector<bool> is_prime(1e8, true);

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 1e8; i++) {
        if (!is_prime[i])
            continue;

        for (int j = i * i; j < 1e8; j += i) {
            is_prime[j] = false;
        }
    }
    return is_prime;
}

int solution(string numbers) {
    for (auto num : numbers)
        numList.push_back(num - '0');

    visited.assign(numbers.size(), false);
    for (int i = 1; i <= numbers.size(); i++) {
        result.assign(i, 0);
        backtracking(0, i);
    }

    int answer = 0;
    vector<bool> is_prime = isPrime();
    for (auto num : ss) {
        if (is_prime[num])
            answer++;
    }

    return answer;
}