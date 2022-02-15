/*
    벽 부수고 이동하기
    https://www.acmicpc.net/problem/2206
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

const int INF = 1000000;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int N, M;
int board[1000][1000];
int dist[1000][1000][2];
queue<vector<int>> q;

int main() {
    char s[1001];
    scanf("%d%d", &N, &M);
    for(int i=0;i<N;i++) {
        scanf("%s", s);
        for(int j=0;j<M;j++) {
            board[i][j] = (s[j]=='1');
            dist[i][j][0] = INF;
            dist[i][j][1] = INF;
        }
    }
    vector<int> temp = {0,0,1,1};
    vector<int> t(4);
    q.push(temp);
    dist[0][0][1] = 1;
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        if(temp[0] == N-1 && temp[1] == M-1) break;
        for(int* v: dir) {
            t = {temp[0]+v[0], temp[1]+v[1], temp[2]+1, temp[3]};
            if(0<=t[0] && t[0]<N && 0<=t[1] && t[1] < M) {
                if(t[3] == 0 && board[t[0]][t[1]] == 1) continue;
                if(t[2] < dist[t[0]][t[1]][t[3]]) {
                    if(t[3] == 1 && board[t[0]][t[1]] == 1) t[3] = 0;
                    q.push(t);
                    dist[t[0]][t[1]][t[3]] = t[2];
                }
            }
        }
    }

    int res = min(dist[N-1][M-1][0], dist[N-1][M-1][1]);
    if(res == INF) printf("-1");
    else printf("%d", res);
}