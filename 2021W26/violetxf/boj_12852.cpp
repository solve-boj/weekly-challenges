/*
    1로 만들기 2
    https://www.acmicpc.net/problem/12852
*/
#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    cin>>n;
    int dp[1000001];
    int before[1000001];
    dp[1] = 0;
    before[1] = -1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + 1;
        before[i] = i-1;
        if(i%2==0){
            if(dp[i]>dp[i/2]+1){
                dp[i] = dp[i/2]+1;
                before[i] = i/2;
            }
        }
        if(i%3==0){
            if(dp[i]>dp[i/3]+1){
                dp[i] = dp[i/3]+1;
                before[i] = i/3;
            }
        }
    }
    cout<<dp[n]<<"\n";
    cout<<n<<" ";
    int k = before[n];
    while(k!=-1){
        cout<<k<<" ";
        k = before[k];
    }

}