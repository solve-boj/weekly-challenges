/*
    친구비
    https://www.acmicpc.net/problem/16562
*/
#include <cstdio>

const int MAX_SIZE = 10001;

int p[MAX_SIZE], cost[MAX_SIZE];

// root node의 parent는 0
int find(int n){
    if(!p[n]){ return n; }
    p[n] = find(p[n]);
    return p[n];
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b){ return; }
    if(cost[a] < cost[b]){ p[b] = a; }
    else{ p[a] = b; }
}

int main(void){
    int N, M, k;
    scanf("%d %d %d", &N, &M, &k);

    for(int i=1; i<=N; ++i)
        scanf("%d", &cost[i]);
    
    int v, w;
    for(int i=0; i<M; ++i){
        scanf("%d %d", &v, &w);
        merge(v, w);
    }

    int min_cost = 0;
    for(int i=1; i<=N; ++i)
        if(!p[i]){ min_cost += cost[i]; }

    if(min_cost > k){ printf("Oh no"); }
    else{ printf("%d", min_cost); }

    return 0;
}