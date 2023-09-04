#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int mmax = 0;
    int mmin = 0;

    for (auto size : sizes) {
        int small = min(size[0], size[1]);
        int big = max(size[0], size[1]);

        mmin = max(mmin, small);
        mmax = max(mmax, big);
    }

    return mmin * mmax;
}