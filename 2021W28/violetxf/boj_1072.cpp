/*
    게임
    https://www.acmicpc.net/problem/1072
*/
#include <iostream>
using namespace std;
int main(){
    long long x,y;
    cin>>x>>y; 
    long long z = (y*100)/x;
    long long start = 1;
    long long end = x;
    long long cursor;
    long long ans;
    if(z>=99){
        cout<<-1;
        return 0;
    }
    while(start<=end){
        cursor = (start+end)/2;
        if(((y+cursor)*100)/(x+cursor)!=z){
            end = cursor-1;
            ans = cursor;
        } else {
            start = cursor+1;
        }
    }
    cout<<start;
}