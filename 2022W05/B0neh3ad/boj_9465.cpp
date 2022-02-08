#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int sticker[n][2];
        for(int j=0; j<2; ++j){
            for(int i=0; i<n; ++i){
                cin >> sticker[i][j];
            }
        }

        int dp[n][3];
        dp[0][0] = sticker[0][0];
        dp[0][1] = sticker[0][1];
        dp[0][2] = 0;
        for(int i=1; i<n; ++i){
            dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + sticker[i][0];
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + sticker[i][1];
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]);
        }
        
        cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << "\n";
    }
    return 0;
}