/*
    가계부 (Hard)
    https://www.acmicpc.net/problem/12837
*/
#include <cstdio>
#include <vector>

class Tree{
public:
    int size;
    std::vector<long long> nodes;

    Tree(): size(0){}
    Tree(int n): size(2*n){
        nodes.resize(2*n, 0);
    }

    long long sum(int L, int R, int nodeNum, int nodeL, int nodeR){
        if(R < nodeL || nodeR < L){ return 0; }
        if(L <= nodeL && nodeR <= R){ return nodes[nodeNum]; }
        int mid = (nodeL + nodeR) / 2;
        return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid+1, nodeR);
    }

    void update(int i, long long val){
        i += size/2;
        nodes[i] += val;
        while(i > 1){
            i /= 2;
            nodes[i] = nodes[i*2] + nodes[i*2+1];
        }
    }

    void construct(){
        for(int i=size/2-1; i>0; --i){
            nodes[i] = nodes[i*2] + nodes[i*2+1];
        }
    }
};

int main(void){
    int N, Q;
    scanf("%d %d", &N, &Q);

    int tsize = 1;
    while(tsize < N){ tsize *= 2; }

    Tree t(tsize);
    int op, a;
    long long b;
    for(int i=0; i<Q; ++i){
        scanf("%d %d %lld", &op, &a, &b);
        switch(op){
            case 1:
            t.update(a-1, b);
            break;

            case 2:
            printf("%lld\n", t.sum(a-1, b-1, 1, 0, tsize-1));
            break;
        }
    }
    return 0;
}