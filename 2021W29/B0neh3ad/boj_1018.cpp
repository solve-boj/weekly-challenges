/*
    체스판 다시 칠하기
    https://www.acmicpc.net/problem/1018
*/
#include <iostream>
#include <algorithm>
using namespace std;

char board[50][50];

int solution(int y, int x, char op){
    int ans = 0;
    for(int i=y; i<y+8; ++i){
        for(int j=x; j<x+8; ++j){
            if((i+j-x-y)%2)
                ans += int(board[i][j] != op);
            else
                ans += int(board[i][j] == op);
        }
    }
    return ans;
}

int main(void){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> board[i][j];
        }
    }

    int answer = n*m;
    for(int i=0; i<=n-8; ++i){
        for(int j=0; j<=m-8; ++j){
            int t1 = solution(i, j, 'W'), t2 = solution(i, j, 'B');
            answer = min({answer, t1, t2});
        }
    }

    cout << answer;
    return 0;
}