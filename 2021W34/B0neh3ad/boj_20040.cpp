/*
    사이클 게임
    https://www.acmicpc.net/problem/20040
*/
#include <bits/stdc++.h>

using namespace std;

int find(int num, int p[]){
    if(num == p[num]){ return num; }
    return (p[num] = find(p[num], p));
}

bool merge(int lhs, int rhs, int p[]){
    lhs = find(lhs, p);
    rhs = find(rhs, p);
    if(lhs == rhs){ return false; }
    p[rhs] = lhs;
    return true;
}

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);

    int p[n];
    for(size_t i=0; i<n; ++i){
        p[i] = i;
    }

    int ans = 0;
    bool flag = false;
    for(size_t i=0; i<m; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        if(!merge(a, b, p) && !flag){
            ans = i+1;
            flag = true;
        }
    }

    printf("%d", ans);
    return 0;
}