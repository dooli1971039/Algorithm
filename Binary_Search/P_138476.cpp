#include <algorithm>
#include <vector>
using namespace std;

int solution(int k, vector<int> tangerine) {
    sort(tangerine.begin(), tangerine.end());

    vector<int> tangerineSize;

    int idx = 0;
    while (true) {
        if (idx >= tangerine.size())
            break;
        auto k = upper_bound(tangerine.begin(), tangerine.end(), tangerine[idx]);
        int num = k - lower_bound(tangerine.begin(), tangerine.end(), tangerine[idx]);

        tangerineSize.push_back(num);
        idx = k - tangerine.begin();
    }

    sort(tangerineSize.begin(), tangerineSize.end(), greater<>());

    int cnt = 0;
    while (k > 0) {
        k -= tangerineSize[cnt];
        cnt++;
    }

    return cnt;
}