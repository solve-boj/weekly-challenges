/*
    수들의 합
    https://www.acmicpc.net/problem/1789
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

class VI
{
    ull _N;
public:
    using iterator_category = random_access_iterator_tag;
    using difference_type   = ull;
    using value_type        = ull;
    using pointer           = ull*;
    using reference         = ull&;
    VI(ull N):_N(N) {}
    ull operator*() { return _N * (_N+1) / 2; }
    operator ull&() { return _N; }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ull S;
    cin >> S;
    
    cout << --upper_bound(VI(1),VI(1<<17),S);
}