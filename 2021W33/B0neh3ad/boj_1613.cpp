/*
    역사
    https://www.acmicpc.net/problem/1613
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);

    int order[n][n];
    int u, v;
    for(int i=0; i<n; ++i){ fill(order[i], order[i]+n, 0); }
    for(int i=0; i<k; ++i){
        scanf("%d %d", &u, &v);
        order[u-1][v-1] = 1;
    }

    for(int k=0; k<n; ++k){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(order[i][k] & order[k][j])
                    order[i][j] = 1;
            }
        }
    }

    int s;
    scanf("%d", &s);
    for(int i=0; i<s; ++i){
        scanf("%d %d", &u, &v);
        --u; --v;
        if(order[u][v]){ printf("-1\n"); }
        else if(order[v][u]){ printf("1\n"); }
        else{ printf("0\n"); }
    }
    return 0;
}