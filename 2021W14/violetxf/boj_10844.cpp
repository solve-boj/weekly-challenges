#include <iostream>
using namespace std;
int main(){
    int dp[101][10]; //count of each digit
    dp[1][0]=0;
    for(int i=1;i<=9;i++)
        dp[1][i]=1;
    int N;
    cin>>N;
    for(int i=2;i<=N;i++){
        dp[i][0]=dp[i-1][1];
        dp[i][9]=dp[i-1][8];
        for(int k=1;k<=8;k++){
            dp[i][k]=(dp[i-1][k-1]+dp[i-1][k+1])%1000000000;
        }
    }
    int result = 0;
    for(int i=0;i<=9;i++){
        result += dp[N][i];
        result %= 1000000000;
    }
    cout<<result;
    
}