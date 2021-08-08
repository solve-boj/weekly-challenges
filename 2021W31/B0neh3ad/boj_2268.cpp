/*
    수들의 합
    https://www.acmicpc.net/problem/2268
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
        nodes[i] = val;
        while(i > 1){
            i /= 2;
            nodes[i] = nodes[i*2] + nodes[i*2+1];
            // 결국 val을 특정 nodes들에 더해나가는 것이므로... bit masking으로 최적화 가능?
        }
    }
};

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);

    int tsize = 1;
    while(tsize < N){ tsize *= 2; }
    
    Tree t(tsize);
    int op, idx;
    long long param;
    for(int i=0; i<M; ++i){
        scanf("%d %d %lld", &op, &idx, &param);
        switch(op){
            case 0:
            printf("%lld\n", (idx > param) ? t.sum(param-1, idx-1, 1, 0, tsize-1) : t.sum(idx-1, param-1, 1, 0, tsize-1));
            break;

            case 1:
            t.update(idx-1, param);
            break;
        }
    }

    return 0;
}