/*
    [미포함]5의 수난
    https://www.acmicpc.net/problem/23037
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    int answer = 0;
    for(int i=0; i<5; ++i, n/=10)
        answer += pow(n%10, 5);
    printf("%d", answer);
    return 0;
}