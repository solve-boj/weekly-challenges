/*
    스도쿠
    https://www.acmicpc.net/problem/2580
*/

#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
bool candidate[9][9][10];
vector<pair<int, int>> slots;
bool done = false;

void f(int n) {
    if(done) return;
    if(n==slots.size()) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        done=true;
        return;
    }
    int x = slots[n].first, y = slots[n].second;
    fill(candidate[x][y]+1, candidate[x][y]+10, true);
    for(int i=0;i<9;i++) {
        candidate[x][y][board[i][y]] = false;
    }
    for(int j=0;j<9;j++) {
        candidate[x][y][board[x][j]] = false;
    }
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            candidate[x][y][board[x/3*3+i][y/3*3+j]] = false;
        }
    }
    for(int i=1;i<=9;i++) {
        if(candidate[x][y][i]) {
            board[x][y] = i;
            f(n+1);
        };
    }
    board[x][y] = 0;
}   

int main() {
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            scanf("%d", &board[i][j]);
            if(!board[i][j]) {
                slots.push_back({i, j});
            }
        }
    }
    f(0);
}

