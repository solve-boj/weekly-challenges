/*
    벽 부수고 이동하기 2
    https://www.acmicpc.net/problem/14442
*/
#include <bits/stdc++.h>

using namespace std;

// N E [begin, end)
bool in_range(size_t N,size_t begin, size_t end)
{
    return begin <= N && N < end;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t N, M, K;
    cin >> N >> M >> K;
    ++K;

    vector<vector<size_t>> grid(N, vector<size_t>(M));
    string line;
    for(auto& c:grid)
        for(auto& v:c){
            char c;
            cin >> c;
            v = c - '0';
        }

    vector<vector<vector<size_t>>> result(K);
    for(auto& c:result){
        c.resize(N, vector<size_t>(M,-1));
        c[0][0] = 1;
    }

    queue<pair<size_t,pair<size_t,size_t>>> q;
    q.emplace(0,make_pair(0,0));

    while(not q.empty()){
        auto[idx,pos] = q.front();
        auto[x,y] = pos;
        q.pop();

        static int dx[] = {1,-1,0,0};
        static int dy[] = {0,0,1,-1};
        for(size_t i=0; i!=4; ++i){
            size_t mx = x + dx[i];
            size_t my = y + dy[i];

            if(not in_range(mx,0,N) or not in_range(my,0,M))
                continue;

            size_t midx = idx + grid[mx][my];   
            
            if(not in_range(midx,0,K))
                continue;
            
            if(result[midx][mx][my] != -1)
                continue;
                
            for(size_t i=midx; i!=K; ++i)
                result[i][mx][my] = min(result[i][mx][my], result[idx][x][y] + 1);
            
            q.emplace(midx,make_pair(mx,my));
        }
    }

    size_t answer = -1;
    for(size_t i=0; i!=K; ++i)
        answer = min(answer, result[i][N-1][M-1]);
    
    cout << (int)answer;
}