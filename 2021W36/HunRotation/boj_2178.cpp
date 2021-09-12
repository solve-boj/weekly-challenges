/*
    미로 탐색
    https://www.acmicpc.net/problem/2178
*/

#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
char board[100][101];
bool vis[100][100];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<vector<int>> q;

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++) {
        if (i==N-1) scanf("%s", board[i]);
        else scanf("%s\n", board[i]);
    }
    vector<int> v = {0, 0, 1};
    q.push(v);
    vis[0][0] = true;
    int r, c, level, newr, newc, ans = -1;
    while (!q.empty()) {
        r=q.front()[0]; c=q.front()[1]; level=q.front()[2];
        q.pop();
        if(r == N-1 && c == M-1) {
            ans = level;
        }
        for(int i=0;i<4;i++) {
            newr = r+dir[i][0]; newc = c+dir[i][1];
            if(0<=newr && newr<N && 0<=newc && newc<M &&
            board[newr][newc] == '1' && !vis[newr][newc]) {
                v = {newr, newc, level+1};
                q.push(v);
                vis[newr][newc] = true;
            }
        }
    }
    printf("%d", ans);
}

// keyword: BFS
// 시간복잡도: O(N^2)
/*
idea: 간단한 BFS, 인접 위치들을 dir을 이용해 찾음, 
칸의 범위를 벗어나거나 벽이 아니면 queue에 투입
*/