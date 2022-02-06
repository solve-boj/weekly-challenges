#include <bits/stdc++.h>
using namespace std;

int mat[500][2];
int dp[500][500];

int sol(int s, int e){
    if(s == e || dp[s][e]){ return dp[s][e]; }

    int res = INT_MAX;
    for(int m=s; m<e; ++m){
        res = min(res, sol(s, m) + sol(m+1, e) + mat[s][0]*mat[m][1]*mat[e][1]);
    }

    dp[s][e] = res;
    return dp[s][e];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    for(int i=0; i<n; ++i){
        cin >> mat[i][0] >> mat[i][1];
    }

    cout << sol(0, n-1);
    return 0;
}