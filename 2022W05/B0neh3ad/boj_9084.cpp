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

        int coin[n];
        for(int i=0; i<n; ++i){
            cin >> coin[i];
        }

        int m;
        cin >> m;

        int dp[m+1] = {0, };
        dp[0] = 1;
        for(int i=0; i<n; ++i){
            for(int j=coin[i]; j<=m; ++j){
                dp[j] += dp[j-coin[i]];
            }
        }

        cout << dp[m] << "\n";
    }
    return 0;
}