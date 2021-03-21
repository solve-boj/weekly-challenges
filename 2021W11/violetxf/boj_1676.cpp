
/*
    팩토리얼 0의 개수
    https://www.acmicpc.net/problem/1676
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin>>N;
    int two=0, five=0;
    for(int i=2;i<=N;i*=2){
        two+=N/i;
    }
    for(int i=5;i<=N;i*=5){
        five+=N/i;
    }
    cout<<min(two,five);
}