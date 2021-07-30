/*
    이항 계수 3
    https://www.acmicpc.net/problem/11401
*/
#include <cstdio>
using namespace std;

unsigned long long sqr(int a, int n){
    if(n == 0){ return 1; }
    if(n == 1){ return a; }

    unsigned long long temp = sqr(a, n/2);
    if(n%2){ return ((temp*temp)%1000000007*a)%1000000007; }
    else{ return (temp*temp)%1000000007; }
}

int main(void){
    int N, K;
    scanf("%d %d", &N, &K);

    unsigned long long son = 1, mom = 1;
    for(int i=0; i<N; ++i){
        son = (son*(i+1)) % 1000000007;
    }
    for(int i=0; i<K; ++i){
        mom = (mom*(i+1)) % 1000000007;
    }
    for(int i=0; i<N-K; ++i){
        mom = (mom*(i+1)) % 1000000007;
    }

    mom = sqr(mom, 1000000005);
    unsigned long long result = (son*mom)%1000000007;
    printf("%lld", result);
    return 0;
}

/*
    페르마의 소정리
    근데 아직도 modulo 연산은 정확히 모르겠다
*/