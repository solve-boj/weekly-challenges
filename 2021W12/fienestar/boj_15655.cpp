/*
    N과 M (6)
    https://www.acmicpc.net/problem/15655
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    size_t N, M;
    cin >> N >> M;

    vector<int> now(M);
    vector<int> rep(N);
    for(auto& v:rep)
        cin >> v;
    sort(rep.begin(),rep.end());

    function<void(size_t,size_t)> dfs = [&](size_t i,size_t begin){
        if(i == M){
            for(auto v:now)
                cout << rep[v] << " ";
            cout << "\n";
            return;
        }
        for(size_t k=begin; k<N; ++k){
            now[i] = k;
            dfs(i+1, k+1);
        }
    };

    dfs(0,0);
}