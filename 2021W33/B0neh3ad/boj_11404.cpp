/*
    플로이드
    https://www.acmicpc.net/problem/11404
*/
#include <cstdio>
#include <algorithm>

using namespace std;
const int INF = 1e8;


int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    
    int dist[n][n];
    for(int i=0; i<n; ++i){
        fill(dist[i], dist[i]+n, INF);
        dist[i][i] = 0;
    }

    int a, b, c;
    for(int i=0; i<m; ++i){
        scanf("%d %d %d", &a, &b, &c);
        if(dist[a-1][b-1] > c)
            dist[a-1][b-1] = c;
    }

    for(int k=0; k<n; ++k){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            printf("%d ", (dist[i][j] >= INF) ? 0 : dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
    정당성 증명은 어케 하지?
*/