/*
    수 이어 쓰기 1
    https://www.acmicpc.net/problem/1748
*/
#include <cmath>
#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int cnt = log10(n)+1;
    int sum = 0;
    for(int i=0;i<cnt-1;i++){
        sum+=pow(10,i)*9*(i+1);
    }
    sum+=(n-pow(10,cnt-1)+1)*cnt;
    cout<<sum;
}