/*
    로봇 프로젝트
    https://www.acmicpc.net/problem/3649
*/
#include <bits/stdc++.h>

using namespace std;

void solve(int x)
{
    static int v[1000001];
    size_t n;
    cin >> n;

    x *= 10000000;
    
    for(size_t i=0; i!=n; ++i)
        cin >> v[i];

    sort(v,v+n);

    int a = -1, b = -1;
    int max_diff = -1;

    for(size_t i = 0; i != n; ++i){
        if(v[i] >= x)break;

        auto* found = lower_bound(v,v+i,x-v[i]);
        int diff = abs(*found - v[i]);
        if(v[i] + *found == x && found != v + i && diff > max_diff){
            a = *found;
            b = v[i];
            max_diff = diff;
        }
    }

    if(a == -1)cout << "danger\n";
    else cout << "yes " << a << " " << b << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    while(cin >> x)
        solve(x);
}