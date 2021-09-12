/*
    박스 그림 문자
    https://www.acmicpc.net/problem/23038
*/

#include <cstdio>
#include <algorithm>

using namespace std;

char board[900][900];
int N, M;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0;i<3*N;i++) {
        getchar();
        for(int j=0;j<3*M;j++) {
            board[i][j] = getchar();
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if((i+j) % 2) {
                board[3*i+1][3*j+1] = '#';
                for(int k=0;k<4;k++) {
                    if(i+dr[k]>=0 && i+dr[k]<N && j+dc[k]>=0 && j+dc[k]<M
                    && board[3*i+1+2*dr[k]][3*j+1+2*dc[k]] == '#') {
                        board[3*i+1+dr[k]][3*j+1+dc[k]] = '#';
                    }
                }
            }
        }
    }
    for(int i=0;i<3*N;i++) {
        for(int j=0;j<3*M;j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    
}