/*
    포도주 시식
    https://www.acmicpc.net/problem/2156
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    int arr[n], dp[n+1] = {0, };
    for(int i=0; i<n; ++i){
        scanf("%d", &arr[i]);
    }
    dp[1] = arr[0];
    if(n >= 2)
        dp[2] = dp[1] + arr[1];
    if(n >= 3){
        for(int i=2; i<n; ++i)
            dp[i+1] = max(dp[i], max(arr[i] + dp[i-1], arr[i] + arr[i-1] + dp[i-2]));
    }
    cout << dp[n];
    return 0;
}
/*
    3개 case로 나누는 문제
    (미포함 / 나만 포함/ 나랑 쟤도 포함)
*/