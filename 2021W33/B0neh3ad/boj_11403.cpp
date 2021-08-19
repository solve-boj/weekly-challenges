/*
    경로
    https://www.acmicpc.net/problem/11403
*/
#include <cstdio>
using namespace std;

int main(void){
    int N;
    scanf("%d", &N);

    int dist[N][N];
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            scanf("%d", &dist[i][j]);
        }
    }

    for(int k=0; k<N; ++k){
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                if(dist[i][k] && dist[k][j])
                    dist[i][j] = 1;
            }
        }
    }

    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j)
            printf("%d ", dist[i][j]);
        printf("\n");
    }
    return 0;
}