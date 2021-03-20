/*
    욕심쟁이 판다
    https://www.acmicpc.net/problem/1937
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    size_t n;
    cin >> n;
    
    vector<vector<size_t>> denamu(n,vector<size_t>(n));
    for(size_t i=0;i!=n;++i)
        for(size_t j=0;j!=n;++j)
            cin >> denamu[i][j];

    vector<vector<size_t>> path_len(n,vector<size_t>(n,0));
    function<size_t(size_t,size_t)> dfs = [&](size_t i, size_t j){
        if(path_len[i][j])return path_len[i][j];

        static int di[] = {1,-1,0,0};
        static int dj[] = {0,0,1,-1};

        for(size_t k=0; k!=4; ++k){
            size_t mi = i + di[k];
            size_t mj = j + dj[k];

            if(mi >= n || mj >= n) continue;
            
            if(denamu[i][j] > denamu[mi][mj])
                path_len[i][j] = max(path_len[i][j],dfs(mi,mj));
        }
        return ++path_len[i][j];
    };

    size_t max_path_len = 0;

    for(size_t i=0;i!=n;++i)
        for(size_t j=0;j!=n;++j)
            max_path_len = max(max_path_len, dfs(i,j));

    cout << max_path_len;
}