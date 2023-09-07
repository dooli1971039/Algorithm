#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int answer = 0;

    for (int i = 0; i < citations.size(); i++) {
        // H-index 값은 논문 개수를 넘길 수 없다.
        int hIndex = citations.size() - i; // n개, n-1개, .. 1개
        if (citations[i] >= hIndex)
            return hIndex;
    }

    return answer;
}