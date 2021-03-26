/*
    N과 M (3)
    https://www.acmicpc.net/problem/15651
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

    function<void(size_t,size_t)> dfs = [&](size_t i,size_t begin){
        if(i == M){
            for(auto v:now)
                cout << v << " ";
            cout << "\n";
            return;
        }
        for(size_t k=1; k<=N; ++k){
            now[i] = k;
            dfs(i+1, k+1);
        }
    };

    dfs(0,1);
}