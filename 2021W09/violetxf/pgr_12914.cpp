/*
    멀리 뛰기
    https://programmers.co.kr/learn/courses/30/lessons/12914
*/
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long dp[2001];
    dp[0] = 1;
    dp[1] = 2;
    for(int i=2;i<n;i++){
        dp[i] = (dp[i-1]+dp[i-2])%1234567;
    }
    return dp[n-1];
}