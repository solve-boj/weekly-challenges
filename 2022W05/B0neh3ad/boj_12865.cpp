#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;

    int w[n+1], v[n+1];
    for(int i=1; i<=n; ++i){
        cin >> w[i] >> v[i];
    }

    int dp[k+1] = {0, };
    for(int i=1; i<=n; ++i){
        for(int j=k; j>=w[i]; --j){
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }

    cout << dp[k];
    return 0;
}