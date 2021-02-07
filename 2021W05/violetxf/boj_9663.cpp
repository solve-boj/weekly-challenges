/*
    N-Queen
    https://www.acmicpc.net/problem/9663
*/
#include <iostream>
using namespace std;
int N;
int cases = 0;
int column[16];
bool can_place(int c){
    
    for(int i=0;i<c;i++){
        if(column[i]==column[c]||abs(column[i]-column[c])==c-i)return false;
    }
    return true;
}
void place(int line){
    if(line==N){cases++;return;}
    for(int i=0;i<N;i++){
        column[line] = i;
        if(can_place(line))
            place(line+1);
    }
}
int main(){
    cin>>N;
    place(0);
    cout<<cases;
}