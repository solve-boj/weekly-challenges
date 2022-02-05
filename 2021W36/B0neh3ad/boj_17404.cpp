/*
    RGB거리 2
    https://www.acmicpc.net/problem/17404
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    scanf("%d", &N);
    int arr[N][3];
    int dp[N][3], first[N][3];
    
    scanf("%d %d %d", arr[0][0], arr[0][1], arr[0][2]);
    dp[0][0] = arr[0][0]; first[0][0] = 0;
    dp[0][1] = arr[0][1]; first[0][1] = 1;
    dp[0][2] = arr[0][2]; first[0][2] = 2;

    for(int i=1; i<N; ++i){
        scanf("%d %d %d", arr[i][0], arr[i][1], arr[i][2]);
        if(dp[i-1][1] > dp[i-1][2]){
            dp[i][0] = dp[i-1][1] + arr[i][0];
            first[i][0] = first[i-1][1];
        }
        else{
            dp[i][0] = dp[i-1][2] + arr[i][0];
            first[i][0] = first[i-1][2];
        }
        if(dp[i-1][0] > dp[i-1][2]){
            dp[i][1] = dp[i-1][0] + arr[i][1];
            first[i][1] = first[i-1][0];
        }
        else{
            dp[i][1] = dp[i-1][2] + arr[i][1];
            first[i][1] = first[i-1][2];
        }
        if(dp[i-1][0] > dp[i-1][1]){
            dp[i][2] = dp[i-1][0] + arr[i][2];
            first[i][2] = first[i-1][0];
        }
        else{
            dp[i][2] = dp[i-1][1] + arr[i][2];
            first[i][2] = first[i-1][1];
        }
    }
    return 0;
}