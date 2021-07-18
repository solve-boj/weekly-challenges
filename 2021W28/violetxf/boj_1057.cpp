/*
    토너먼트
    https://www.acmicpc.net/problem/1057
*/
#include <iostream>
using namespace std;

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    
    int answer = 0;
    while(a!=b){
        a = (a+1)/2;
        b = (b+1)/2;
        answer++;
    }
    cout<<answer;
}