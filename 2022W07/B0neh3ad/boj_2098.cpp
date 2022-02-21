#include <bits/stdc++.h>
using namespace std;
#define MAX 100000000

int n;
int w[16][16];
int dp[16][1 << 16];

int sol(int curr, int visited){
    if(dp[curr][visited] != -1){ return dp[curr][visited]; }
    if(visited == (1 << n) - 1){
        if(!w[curr][0]){
            return MAX;
        }
        dp[curr][visited] = w[curr][0];
        return dp[curr][visited];
    }

    dp[curr][visited] = MAX;
    for(int i=0; i<n; ++i){
        if(w[curr][i] && !(visited & (1 << i))){
            dp[curr][visited] = min(dp[curr][visited], w[curr][i] + sol(i, visited | (1 << i)));
        }
    }
    return dp[curr][visited];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> w[i][j];
        }
    }

    cout << sol(0, 1);

    return 0;
}