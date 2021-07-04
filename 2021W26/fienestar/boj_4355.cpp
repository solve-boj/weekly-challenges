/*
    서로소
    https://www.acmicpc.net/problem/4355
*/
#include <bits/stdc++.h>

using namespace std;
using ull = long long;

void solve(ull n)
{
    ull rslt = n;

    if(n%2 == 0){
        while(n%2 == 0)n/=2;
        rslt -= rslt/2;
    }

    if(n%3 == 0){
        while(n%3 == 0)n/=3;
        rslt -= rslt/3;
    }

    for(ull i=5; i*i <= n; i+=6){
        if(n%i == 0){
            while(n%i == 0)n/=i;
            rslt -= rslt/i;
        }

        ull k = i+2;
        if(n%k == 0){
            while(n%k == 0)n/=k;
            rslt -= rslt/k;
        }
    }

    if(n>1) rslt-=rslt/n;

    cout << rslt << "\n";
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	ull n;

	while(cin >> n && n)
		solve(n);
}