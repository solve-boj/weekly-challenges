/*
    1, 2, 3 더하기
    https://www.acmicpc.net/problem/9095
*/
#include <cstdio>

int memo[12];

int main(void){
    int T;
    scanf("%d", &T);

    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;
    for(int i=4; i<=11; ++i)
        memo[i] = memo[i-1]+memo[i-2]+memo[i-3];

    int n;
    for(int i=0; i<T; ++i){
        scanf("%d", &n);
        printf("%d\n", memo[n]);
    }

    return 0;
}