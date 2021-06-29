/*
	1의 개수 세기
	https://www.acmicpc.net/problem/9527
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull popcount(ull n)
{
    ull c = 0;
    while(n){
        ++c;
        n = n&(n-1);
    }
    return c;
}

ull count(ull n)
{
    ull bit_count = popcount(n);
    ull count = 0;
    for(size_t i=0; i!=54; ++i)
        if(n & (1ull << i)){
            count += --bit_count * (1ull << i);
            count += i * (1ull<<(i-1));
            count += 1;
            n ^= (1ull << i);
        }
    return count;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    ull A, B;
    cin >> A >> B;

    cout << count(B) - count(A-1);
}