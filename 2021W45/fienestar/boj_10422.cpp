/*
    괄호
    https://www.acmicpc.net/problem/10422
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    ull dp[5001]={1};
    for(size_t i=2; i<=5000; i+=2)
        for(size_t j=2; j<=i; j+=2)
            dp[i] = (dp[i]+dp[j-2]*dp[i-j]) % 1'000'000'007;

    size_t T;
    cin >> T;

    while(T--){
        size_t L;
        cin >> L;
        cout << dp[L] << "\n";
    }
}