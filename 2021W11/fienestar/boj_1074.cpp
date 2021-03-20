/*
    Z
    https://www.acmicpc.net/problem/1074
*/

#include <bits/stdc++.h>

using namespace std;

size_t get(size_t N,size_t r,size_t c)
{
    if(N == 1)
        return 0;
    
    N>>=1;

    return r/N*N*N*2 + c/N*N*N + get(N, r%N, c%N);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t N;
    size_t r,c;
    cin >> N >> r >> c;
    cout << get(1 << N,r,c);
}