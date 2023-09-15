#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
unordered_set<int> sum_set;
int originLen;

void calcSum(int len, vector<int> &elements) {
    int ssum = 0;
    for (int i = 0; i < len; i++) { // len개만큼 넣기
        ssum += elements[i];
    }
    sum_set.insert(ssum);

    for (int i = 0; i < originLen; i++) {
        ssum = ssum - elements[i] + elements[i + len];
        sum_set.insert(ssum);
    }
}

int solution(vector<int> elements) {
    originLen = elements.size();
    for (int i = 0; i < originLen - 1; i++) {
        elements.push_back(elements[i]);
    } // [7,9,1,1,4] -> [7,9,1,1,4,7,9,1,1]

    for (int i = 1; i <= originLen; i++) {
        calcSum(i, elements);
    }

    int answer = sum_set.size();
    return answer;
}