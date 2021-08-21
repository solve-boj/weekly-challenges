/*
    타일 채우기
    https://www.acmicpc.net/problem/2133
*/
#include <cstdio>

using namespace std;

int main(void){
    int N;
    scanf("%d", &N);
    if(N%2){ printf("0"); }
    else{
        N /= 2;
        long long a[N+1];
        a[0] = 1;
        a[1] = 3;
        for(int i=2; i<=N; ++i){
            a[i] = 3*a[i-1];
            for(int j=2; j<=i; ++j){
                a[i] += 2*a[i-j];
            }
        }
        printf("%d", a[N]);
    }
    return 0;
}
/*
    N이 홀수인 경우
    1) 3X2 칸이 남았을 때
    앞서 채운 칸(3X홀수)이 다 채워져 있다면
    채울 수 있다. 순환논리에 빠지므로 패스.
    2) 3X1 칸이 남았을 때
    못 채운다
    1) 2)에 의해 N이 홀수인 경우 = 0
    N이 짝수인 경우
    -> base case가 N=2, N=4일 때이므로
    귀납적으로 계산 가능!
*/