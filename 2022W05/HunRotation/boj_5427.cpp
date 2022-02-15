/*
    불
    https://www.acmicpc.net/problem/5427
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

const int INF = 1000000;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int t, w, h;
char board[1000][1001];
bool vis[1000][1000];
queue<vector<int>> q;
pair<int, int> start;
vector<pair<int, int>> fires;
int res = INF;
bool flag;

int main() {
    vector<int> temp;
    scanf("%d", &t);
    for(int k=0;k<t;k++) {
        flag = false;
        res = INF;
        scanf("%d %d", &w, &h);
        for(int i=0;i<h;i++) {
            scanf("%s", board[i]);
            for(int j=0;j<w;j++) {
                if(board[i][j] == '@') {
                    start = {i, j};
                }
                if(board[i][j] == '*') {
                    fires.push_back({i, j});
                }
            }
        }

        for(pair<int, int> p: fires) {
            temp = {p.first, p.second, -1};
            q.push(temp);
        }
        q.push({start.first, start.second, 0});
        vis[start.first][start.second] = true;

        while(!q.empty()) {
            temp = q.front();
            //printf("pop: %d %d %d\n", temp[0], temp[1], temp[2]);
            q.pop();
            for(int* v: dir) {
                vector<int> t = {temp[0]+v[0], temp[1]+v[1], temp[2]};
                if(!(0<=t[0] && t[0]<h && 0<=t[1] && t[1]<w)) {
                    if(t[2] != -1) {
                        res = t[2]+1;
                        flag = true;
                        goto a;
                    }
                }
                else if(board[t[0]][t[1]] != '#' && board[t[0]][t[1]] != '*' && !vis[t[0]][t[1]]) {
                    if(t[2] == -1) {
                        board[t[0]][t[1]] = '*';
                        //printf("push: %d %d %d\n", t[0], t[1], t[2]);
                        q.push(t);
                    }
                    else {
                        ++t[2];
                        vis[t[0]][t[1]] = true;
                        //printf("push: %d %d %d\n", t[0], t[1], t[2]);
                        q.push(t);
                    }
                }

            }
        }

        a: if(flag) {
            printf("%d\n", res);
        }
        else {
            printf("IMPOSSIBLE\n");
        }
        while(!q.empty()) {
            q.pop();
        }
        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                vis[i][j]=false;
            }
        }
        fires.clear();
    }
}