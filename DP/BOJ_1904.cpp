#include <iostream>
using namespace std;

// 1
// 11, 00
// 111, 001, 100
// 1111, 0000, 1100, 0011, 1001

int main() {
    int n;
    cin>>n;
    int dp[n+1];

    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-2]+dp[i-1])%15746;
    }
    cout<<dp[n];
}