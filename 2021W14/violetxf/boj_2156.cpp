#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int vol[10001]={0};
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>vol[i];
    }
    int dp[10001][2];
    dp[0][0]=0;
    dp[0][1]=0;
    dp[1][1]=vol[1];
    dp[1][0]=vol[1];
    dp[2][0]=vol[2];
    dp[2][1]=vol[1]+vol[2];
    for(int i=3;i<=n;i++){
        dp[i][0]=max(max(dp[i-2][1],dp[i-2][0]),max(dp[i-3][1], dp[i-3][0]))+vol[i];
        dp[i][1]=dp[i-1][0]+vol[i];
    }
    cout<<max(max(dp[n][0],dp[n][1]),max(dp[n-1][0],dp[n-1][1]));
}