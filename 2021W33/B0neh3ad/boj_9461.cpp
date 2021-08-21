/*
    파도반 수열
*/
#include <cstdio>

using namespace std;

int main(void){
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; ++t){
        int N;
        scanf("%d", &N);
        if(N <= 3){
            printf("1\n");
        }
        else if(N <= 5){
            printf("2\n");
        }
        else{
            long long P[N];
            P[0] = P[1] = P[2] = 1;
            P[3] = P[4] = 2;
            for(int i=5; i<=N; ++i){
                P[i] = P[i-1] + P[i-5];
            }
            printf("%lld\n", P[N-1]);
        }
    }
    return 0;
}