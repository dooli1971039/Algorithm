#include <vector>

long long sum(std::vector<int> &a) {
    long long ssum = 0;
    for (int i = 0; i < a.size(); i++) {
        ssum += a[i];
    }
    return ssum;
}