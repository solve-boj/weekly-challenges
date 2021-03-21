/*
    프렌즈4블록
    https://programmers.co.kr/learn/courses/30/lessons/17679
*/
#include <string>
#include <vector>
#include <iostream>
#define BLANK '_'
using namespace std;
int H,W;

int step(vector<string> &board){
    bool mark[31][31]={0};
    for(int i=0;i<H-1;i++){
        for(int k=0;k<W-1;k++){
            
            char crt = board[i][k];
            if(crt==BLANK) continue;
            //check square
            if(board[i][k+1]==crt &&
                board[i+1][k]==crt &&
                board[i+1][k+1]==crt){
                    //mark
                    mark[i][k]=mark[i][k+1]=mark[i+1][k]=mark[i+1][k+1]=true;
                }
        }
    }
    int pops = 0;
    for(int i=0;i<H;i++){
        for(int k=0;k<W;k++){
            if(mark[i][k]){
                pops++;
                //pop
                for(int j=i;j>=0;j--){
                    if(j==0){
                        board[j][k]=BLANK;
                    } else {
                        board[j][k]=board[j-1][k];
                    }
                }
            }
        }
    }
    return pops;
}
int solution(int m, int n, vector<string> board) {

    H=m;
    W=n;
    int sum = 0;
    int temp;

    while((temp=step(board))!=0){
        sum+=temp;
    }
    return sum;
}
int main(){
    cout<<solution(4,5,{"CCBDE", "AAADE", "AAABF", "CCBBF"});
}