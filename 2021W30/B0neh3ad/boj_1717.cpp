/*
    집합의 표현
    https://www.acmicpc.net/problem/1717
*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>

const int MAX_SIZE = 1000001;

class UnionFind{
public:
    int p[MAX_SIZE];

    UnionFind(){
        std::fill(p, p+MAX_SIZE, -1);
    }

    int find(int n){
        if(p[n] < 0){ return n; }
        p[n] = find(p[n]);
        return p[n];
    }

    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b){ return; }
        p[a] += p[b];
        p[b] = a;
    }
};

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);

    UnionFind uf;
    int op, a, b;
    for(int i=0; i<m; ++i){
        scanf("%d %d %d", &op, &a, &b);
        switch(op){
            case 0:
            uf.merge(a, b);
            break;

            case 1:
            (uf.find(a) == uf.find(b)) ? printf("YES\n") : printf("NO\n");
            break;
        }
    }

    return 0;
}