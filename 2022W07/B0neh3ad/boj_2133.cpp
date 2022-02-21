#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;

    int dp[n][1 << 3];
    memset(dp, 0, sizeof(dp));

    dp[0][0b000] = dp[0][0b110] = dp[0][0b011] = 1;
    for(int i=1; i<n; ++i){
        dp[i][0b000] = dp[i-1][0b111];
        dp[i][0b100] = dp[i-1][0b011];
        dp[i][0b001] = dp[i-1][0b110];
        dp[i][0b110] = dp[i-1][0b111] + dp[i-1][0b001];
        dp[i][0b011] = dp[i-1][0b111] + dp[i-1][0b100];
        dp[i][0b111] = dp[i-1][0b011] + dp[i-1][0b110] + dp[i-1][0b000];
    }

    cout << dp[n-1][0b111];
    return 0;
}