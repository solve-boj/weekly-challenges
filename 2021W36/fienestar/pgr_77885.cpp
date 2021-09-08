/*
    2개 이하로 다른 비트
    https://programmers.co.kr/learn/courses/30/lessons/77885
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll f(ll n)
{
    ll k = (((n + 1) ^ n) + 1) >> 1;
    n |= k;
    n ^= k >> 1;
    return n;
}

vector<long long> solution(vector<long long> numbers)
{
    for(auto& n:numbers)
        n = f(n);
    return numbers;
}
