/*
    쉬운 계단 수
    https://www.acmicpc.net/problem/10844
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    scanf("%d", &N);
    long long digit[10] = {0, };
    for(int i=1; i<10; ++i){ digit[i] = 1; }

    for(int i=1; i<N; ++i){
        long long next_digit[10] = {0, };
        for(int j=0; j<10; ++j){
            if(j != 0){ next_digit[j-1] += digit[j]; }
            if(j != 9){ next_digit[j+1] += digit[j]; }
        }
        for(int j=0; j<10; ++j){ digit[j] = next_digit[j] % 1000000000; }
    }

    long long res = 0;
    for(int i=0; i<10; ++i){ res += digit[i]; }
    cout << res % 1000000000;
    return 0;
}