/*
    01타일
    https://www.acmicpc.net/problem/1904
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    size_t dp[1000001] = {1,1};

    size_t N;
    cin >> N;
    for(size_t i=2; i<=N; ++i)
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;

    cout << dp[N];
}