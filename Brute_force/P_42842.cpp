#include <string>
#include <vector>

/* (a>=b , a가 가로, b가 세로)
 * yellow : a*b 개
 * brown : 2a + 2b + 4 개
 */

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int i = 1; i <= 2498; i++) {
        for (int j = i; j <= 2498; j++) {
            int br = 2 * i + 2 * j + 4;
            int ye = i * j;

            if (br == brown && ye == yellow) {
                answer.push_back(max(i + 2, j + 2));
                answer.push_back(min(i + 2, j + 2));
                return answer;
            }
        }
    }
}