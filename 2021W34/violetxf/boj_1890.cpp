/*
    점프
    https://www.acmicpc.net/problem/1890
*/
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int board[101][101];
    cin>>n;
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            cin>>board[i][k];
        }
    }
    unsigned long long dp[101][101]={0};
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            if(
                dp[i][k]==0//올 수 없음
                ||(i==n-1 && k==n-1)//종착지
            )continue;
            int jump = board[i][k];
            if(i+jump<n) dp[i+jump][k]+=dp[i][k];
            if(k+jump<n) dp[i][k+jump]+=dp[i][k];
        }
    }
    cout<<dp[n-1][n-1];

}