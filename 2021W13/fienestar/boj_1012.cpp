/*
    유기농 배추
    https://www.acmicpc.net/problem/1012
*/
#include <bits/stdc++.h>

using namespace std;

size_t solve()
{
    size_t M,N,K;
    cin >> M >> N >> K;

    vector<vector<bool>> stat(M,vector<bool>(N, false));
    while(K--){
        size_t X,Y;
        cin >> X >> Y;
        stat[X][Y] = true;
    }

    auto bfs = [&](size_t i,size_t j){
        queue<pair<size_t,size_t>> q;
        q.emplace(i,j);
        stat[i][j] = false;

        while(not q.empty()){
            auto[x,y] = q.front();
            q.pop();

            static int dx[] = {1,-1,0,0};
            static int dy[] = {0,0,1,-1};
            for(size_t k=0; k!=4; ++k){
                size_t mx = x + dx[k];
                size_t my = y + dy[k];
                if(mx < M && my < N && stat[mx][my]){
                    stat[mx][my] = false;
                    q.emplace(mx,my);
                }
            }
        }
    };

    size_t count = 0;
    for(size_t i=0; i!=M; ++i)
        for(size_t j=0; j!=N; ++j)
            if(stat[i][j]){
                bfs(i,j);
                ++count;
            }

    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    size_t T;
    cin >> T;

    while(T--)
        cout << solve() << "\n";
}