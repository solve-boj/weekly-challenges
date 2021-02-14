/*
    회의실 배정
    https://www.acmicpc.net/problem/1931
*/

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int main()
{
    size_t N;
    cin >> N;

    vector<pii> v(N);
    for(auto& c:v)
        cin >> c.first >> c.second;

    sort(v.begin(),v.end(),[](pii a,pii b){
        if(a.second == b.second)
            return less<int>()(a.first,b.first);
        return less<int>()(a.second,b.second);
    });

    int last = 0;
    size_t cnt = 0;
    for(auto& c:v)
        if(c.first >= last){
            ++cnt;
            last = c.second;
        }
    cout << cnt;
}