/*
    1로 만들기
    https://www.acmicpc.net/problem/1463
*/
#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001];
int n;
int func(int i){
    
    if(i>n)return 987654321;
    //cout<<i<<"\n";
    if(dp[i]==0){
        dp[i] = min(func(i+1),min(func(i*2), func(i*3)))+1;
    }
    return dp[i];
}
int main(){
    
    
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    if(n%3==0){
        dp[n/3] = 1;
    }
    if(n%2==0){
        dp[n/2] = 1;
    }
    dp[n-1] = 1;
    
    cout<<func(1);

}