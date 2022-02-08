#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int cnt = 0;
    vector<int> val, weight;
    for(int i=0; i<n; ++i){
        int w, v, k;
        cin >> w >> v >> k;
        for(int j=1; j<=k; ++j){
            val.push_back(v);
            weight.push_back(w);
        }
        cnt += k;
    }

    int dp[m+1] = {0, };
    for(int i=0; i<cnt; ++i){
        for(int j=m; j>=weight[i]; --j){
            dp[j] = max(dp[j], dp[j-weight[i]]+val[i]);
        }
    }
    cout << dp[m];
    return 0;
}