/*
    윌리암슨수액빨이딱따구리가 정보섬에 올라온 이유
    https://www.acmicpc.net/problem/17129
*/
#include <bits/stdc++.h>

using namespace std;

bool in_range(size_t n, size_t begin, size_t end)
{
    return begin <= n && n < end;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t N,M;
    cin >> N >> M;

    vector<string> A(N);
    for(auto& s:A)
        cin >> s;

    vector<vector<size_t>> time(N,vector<size_t>(M));
    queue<pair<size_t,size_t>> q;
    for(size_t i=0; i!=N; ++i)
        for(size_t j=0; j!=M; ++j)
            if(A[i][j] == '2'){
                q.emplace(i,j);
                time[i][j] = 1;
            }

    while(!q.empty())
    {
        auto[x,y] = q.front();
        q.pop();

        static int dx[] = {1,-1,0,0};
        static int dy[] = {0,0,1,-1};

        for(size_t i=0; i!=4; ++i){
            size_t mx = x + dx[i];
            size_t my = y + dy[i];

            if(not in_range(mx,0,N) or not in_range(my,0,M))
                continue;

            if(time[mx][my] or A[mx][my] == '1')
                continue;
            
            time[mx][my] = time[x][y] + 1;
            q.emplace(mx,my);

            if(A[mx][my] >= '3'){
                cout << "TAK\n" << time[mx][my] - 1;
                return 0;
            }
        }
    }

    cout << "NIE";
}