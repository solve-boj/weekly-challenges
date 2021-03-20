/*
    부분합
    https://www.acmicpc.net/problem/1806
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, S;
    cin >> N >> S;

    vector<int> s(N + 1);
    
    for(size_t i=1; i<= N; ++i){
        int ai;
        cin >> ai;
        s[i] += s[i-1] - ai;
    }

    size_t min_length = -1;
    for(auto it = s.rbegin(); it != s.rend(); ++it){
        auto found = lower_bound(it,s.rend(),*it + S);
        if(found == s.rend()) continue;
        min_length = min(min_length, size_t(found - it));
    }

    if(min_length == -1)
        cout << 0;
    else
        cout << min_length;
}