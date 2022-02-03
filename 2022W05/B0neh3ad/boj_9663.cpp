#include <bits/stdc++.h>
using namespace std;

int n, ans;
int board[3][29]; // 세로, 대각 2개(/, \)

void sol(int y, int x, int cnt){
    if(cnt == n){
        ++ans;
        return;
    }

    for(int nx=0; nx<n; ++nx){
        if(board[0][nx]+board[1][y+1+nx]+board[2][y-nx+n]==0){
            board[0][nx]=board[1][y+1+nx]=board[2][y-nx+n]=1;
            sol(y+1, nx, cnt+1);
            board[0][nx]=board[1][y+1+nx]=board[2][y-nx+n]=0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    sol(-1, 0, 0);
    cout << ans;
    return 0;
}