#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>; // (누적 비용, 현재 파일의 크기)

int chap[500];
int dp[500][500];
int psum[501];

int sol(int s, int e){
    if(s == e){ return 0; }
    if(dp[s][e]){ return dp[s][e]; }

    int res = INT_MAX;
    for(int m=s; m<e; ++m){
        res = min(res, sol(s, m) + sol(m+1, e) + psum[e+1] - psum[s]);
    }

    dp[s][e] = res;
    return dp[s][e];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int k;
        cin >> k;

        for(int i=0; i<k; ++i){
            cin >> chap[i];
            psum[i+1] = psum[i] + chap[i];
        }

        for(int i=0; i<k; ++i){
            fill(dp[i], dp[i]+k, 0);
        }

        cout << sol(0, k-1) << "\n";
    }
    return 0;
}