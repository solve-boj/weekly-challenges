/*
    알파벳
    https://www.acmicpc.net/problem/1987
*/

#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int R, C;
int board[20][20];
bool vis[20][20];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int result = 0;
bool use[26];

void bt(int r, int c, int size) {
    result = max(result, size);
    vis[r][c] = true;
    use[board[r][c]-'A'] = true;

    for(int i=0;i<4;i++) {
        if(r+dr[i] >= 0 && r+dr[i] < R && c+dc[i] >= 0 && c+dc[i] < C
        && !use[board[r+dr[i]][c+dc[i]]-'A'] && !vis[r+dr[i]][c+dc[i]]) {
            bt(r+dr[i], c+dc[i], size+1);
        }
    }
    vis[r][c] = false;
    use[board[r][c]-'A'] = false;
}

int main() {
    scanf("%d %d", &R, &C);
    for(int i=0;i<R;i++) {
        getchar();
        for(int j=0;j<C;j++) {
            board[i][j] = getchar();
        }
    }
    use[board[0][0]-'A'] = true;
    bt(0, 0, 1);
    
    printf("%d", result);
}

// keyword: 백트래킹
// 시간복잡도: O(4^26)
/*
idea: result를 항상 함수 처음에 최댓값으로 갱신
인접한 위치가 이미 방문한 곳이 아니고, 알파벳이 기존의 것과 겹치지 않으면 재귀호출
*/