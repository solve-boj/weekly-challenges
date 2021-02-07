/*
    스도쿠
    https://www.acmicpc.net/problem/2580
*/
#include <iostream>
using namespace std;
int board[9][9];
bool row[9][10];//row,number
bool col[9][10];//col,number
bool region[3][3][10];//region_y,region_x,number

void fill_board(int y, int x){
    if(y==9){
        for(int i=0;i<9;i++){
            for(int k=0;k<9;k++){
                cout<<board[i][k]<<" ";
            }
            cout<<endl;
        }
        exit(0);
    }
    int region_y = y/3;
    int region_x = x/3;
    int next_y = y;
    int next_x = x+1;
    if(next_x==9){
        next_y++;
        next_x = 0;
    }
    if(board[y][x] == 0){
        for(int i=1;i<=9;i++){
            if(!row[y][i]&&!col[x][i]&&!region[region_y][region_x][i]){
                board[y][x] = i;
                row[y][i] = true;
                col[x][i] = true;
                region[region_y][region_x][i] = true;
                fill_board(next_y, next_x);
                board[y][x] = 0;
                row[y][i] = false;
                col[x][i] = false;
                region[region_y][region_x][i] = false;
            }
        }
    } else {
        fill_board(next_y, next_x);
    }
}
int main(){
    
    for(int i=0;i<9;i++){
        for(int k=0;k<9;k++){
            int number;
            cin>>number;
            board[i][k] = number;
            int region_y = i/3;
            int region_x = k/3;
            region[region_y][region_x][number] = true;
            row[i][number] = true;
            col[k][number] = true;
        }
    }
    fill_board(0,0);
}