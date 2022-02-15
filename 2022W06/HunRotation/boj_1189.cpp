/*
    컴백홈
    https://www.acmicpc.net/problem/1189
*/

#include <iostream>
#include <vector>

using namespace std;

char area[5][6];
bool vis[5][5];
int R, C, K;
int cnt = 0;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void f(pair<int, int> pos, int length) {
    int r, c;
    if(pos.first == 0 && pos.second == C-1) {
        if(length == K) ++cnt;
        return;
    }
    vis[pos.first][pos.second] = true;
    for(int i=0;i<4;i++) {
        r = pos.first+dir[i][0];
        c = pos.second+dir[i][1];
        if(0<=r && r<R && 0<=c && c<C && area[r][c] == '.' && !vis[r][c]) {
            f({r, c}, length+1);
        }
    }
    vis[pos.first][pos.second] = false;
}

int main() {
    scanf("%d%d%d", &R, &C, &K);
    for(int i=0;i<R;i++) {
        scanf("%s", area[i]);
    }
    f({R-1, 0}, 1);

    printf("%d", cnt);
}