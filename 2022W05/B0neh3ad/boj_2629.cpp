#include <bits/stdc++.h>
using namespace std;
#define MAX_W 15000

bool dp[31][2*MAX_W+1];

int main(void){
    int bn;
    cin >> bn;

    int bw[bn+1];
    for(int i=1; i<=bn; ++i){
        cin >> bw[i];
    }

    int mn;
    cin >> mn;

    int mw[mn];
    for(int i=0; i<mn; ++i){
        cin >> mw[i];
    }

    int sum = 0;
    dp[0][MAX_W] = 1;
    for(int i=1; i<=bn; ++i){
        for(int j=-sum; j<=sum; ++j){
            if(dp[i-1][MAX_W + j]){
                dp[i][MAX_W + j + bw[i]] = dp[i][MAX_W + j - bw[i]] = dp[i][MAX_W + j] = true;
            }
        }
        sum += bw[i];
    }

    for(int i=0; i<mn; ++i){
        cout << ((mw[i] > MAX_W) ? "N" : (dp[bn][MAX_W + mw[i]] ? "Y" : "N")) << " ";
    }
    return 0;
}