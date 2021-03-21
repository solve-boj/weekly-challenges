/*
    이항 계수 2
    https://www.acmicpc.net/problem/11051
*/
#include <iostream>
using namespace std;
int dp[1001][1001]={0};
int comb(int n, int r){
    if(n==r)return 1;
    if(r==0)return 1;
    if(dp[n][r]!=0)return dp[n][r];
    return dp[n][r]=(comb(n-1,r)+comb(n-1, r-1))%10007;
}
int main(){
    int N, K;
    cin>>N>>K;
    cout<<comb(N,K);
}