/*
    상범 빌딩
    https://www.acmicpc.net/problem/6593
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int L, R, C;
char building[30][30][30];
int dist[30][30][30];
queue<vector<int>> q;
int dir[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
vector<int> start(3);
int res;

void bfs(vector<int> start) {
    res = 10000;
    vector<int> temp(4);
    q.push(start);
    building[start[0]][start[1]][start[2]] = '#';
    while(!q.empty()) {
        temp = q.front();
        dist[temp[0]][temp[1]][temp[2]] = temp[3];
        q.pop();

        for(int* v: dir) {
            vector<int> newpos = {temp[0]+v[0], temp[1]+v[1], temp[2]+v[2], temp[3]+1};
            if(0<=newpos[0] && newpos[0]<L &&
            0<=newpos[1] && newpos[1]<R &&
            0<=newpos[2] && newpos[2]<C &&
            building[newpos[0]][newpos[1]][newpos[2]] != '#') {
                q.push(newpos);
                if(building[newpos[0]][newpos[1]][newpos[2]] == 'E') {
                    if(res>newpos[3]) res = newpos[3];
                    break;
                }
                building[newpos[0]][newpos[1]][newpos[2]] = '#';
            }
        }
    }
    while(!q.empty()) {
        q.pop();
    }
}

int main() {
    string in;
    do {
        cin >> L >> R >> C;
        if(L==0 && R==0 && C==0) break;
        for(int i=0;i<L;i++) {
            for(int j=0;j<R;j++) {
                for(int k=0;k<C;k++) {
                    building[i][j][k] = 0;
                    dist[i][j][k] = -1;
                }
            }
        }
        for(int i=0;i<L;i++) {
            for(int j=0;j<R;j++) {
                cin >> in;
                for(int k=0;k<C;k++) {
                    building[i][j][k] = in[k];
                    if(in[k]=='S') {
                        start[0] = i;
                        start[1] = j;
                        start[2] = k;
                    }
                }
            } 
        }

        bfs(start);

        if(res == 10000) {
            printf("Trapped!\n");
        }
        else {
            printf("Escaped in %d minute(s).\n", res);
        }

    } while(1);
}