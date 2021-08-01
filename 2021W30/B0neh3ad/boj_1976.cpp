/*
    여행 가자
    https://www.acmicpc.net/problem/1976
*/
#include <cstdio>

int p[1000];

int find(int n){
    if(p[n] == n){ return n; }
    p[n] = find(p[n]);
    return p[n];
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b){ return; }
    p[b] = a;
}

int main(void){
    int N;
    scanf("%d", &N);

    int M;
    scanf("%d", &M);

    // root node는 p[i] == i
    for(int i=1; i<=200; ++i){ p[i] = i; }

    int st;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            scanf("%d", &st);
            if(st){ merge(i, j); }
        }
    }

    int points[M];
    bool flag = true;
    for(int i=0; i<M; ++i){
        scanf("%d", &points[i]);
        if(i){ if(find(points[i-1]) != find(points[i])){ flag = false; } }
    }

    printf((flag ? "YES" : "NO"));
    return 0;
}

/*
    Union Find 쓸 때는 직접 p 배열 이용하지 말고
    반드시 Find를 이용해서 같은 집합 소속 여부를 판단해야 한다.
*/