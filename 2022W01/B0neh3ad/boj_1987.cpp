#include <bits/stdc++.h>
using namespace std;

int r, c;
int dy[] = {0, -1, 0, 1}, dx[] = {1, 0, -1, 0};
char board[20][20];
bool alpha[26];

int dfs(int y, int x){
    alpha[board[y][x] - 'A'] = true;

    int ans = 0;

    for(int i=0; i<4; ++i){
        int next_y = y + dy[i];
        int next_x = x + dx[i];
        // check boundary
        if(next_y >= 0 && next_y < r && next_x >= 0 && next_x < c){
            // check able to visit
            if(!alpha[board[next_y][next_x] - 'A']){
                ans = max(ans, dfs(next_y, next_x));
            }
        }
    }

    // backtracking
    alpha[board[y][x] - 'A'] = false;

    return ans + 1;
}

int main(void){

    cin >> r >> c;

    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            cin >> board[i][j];
        }
    }

    // init alpha
    for(int i=0; i<26; ++i){
        alpha[i] = false;
    }

    cout << dfs(0, 0);

    return 0;
}