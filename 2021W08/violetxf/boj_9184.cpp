/*
    신나는 함수 실행
    https://www.acmicpc.net/problem/9184
*/
#include <iostream>
using namespace std;
int memo[102][102][102];
int w(int a, int b, int c){
    int& dat = memo[a+50][b+50][c+50];
    if(dat!=0)return dat;
    if(a<=0||b<=0||c<=0) return dat = 1;
    if(a>20||b>20||c>20) return dat = w(20, 20, 20);
    if(a<b && b<c) return dat = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    return dat = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);

}
int main(){
    while(true){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==-1&&b==-1&&c==-1)break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<"\n";
    }
}