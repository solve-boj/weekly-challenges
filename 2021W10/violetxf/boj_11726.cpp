/*
    2×n 타일링
    https://www.acmicpc.net/problem/11726
*/
#include <iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int dp[1001];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=N;i++){
        dp[i]=(dp[i-2]+dp[i-1])%10007;

    }
    cout<<dp[N];
}