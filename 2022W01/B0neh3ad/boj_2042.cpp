/*
    구간 합 구하기
    https://www.acmicpc.net/problem/2042
*/
#include <cstdio>
#include <vector>

template<typename T>
class Tree{
public:
    int size;
    std::vector<T> nodes;

    Tree(): size(0){}
    Tree(int n): size(2*n){
        nodes.resize(2*n, 0);
    }

    T sum(int L, int R, int nodeNum, int nodeL, int nodeR){
        if(R < nodeL || nodeR < L){ return 0; }
        if(L <= nodeL && nodeR <= R){ return nodes[nodeNum]; }
        int mid = (nodeL + nodeR) / 2;
        return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid+1, nodeR);
    }

    void update(int i, T val){
        i += size/2;
        nodes[i] = val;
        while(i > 1){
            i /= 2;
            nodes[i] = nodes[i*2] + nodes[i*2+1];
        }
    }

    void construct(){
        for(int i=size/2-1; i>0; --i)
            nodes[i] = nodes[i*2] + nodes[i*2+1];
    }
};

int main(void){
    int temp, M, K;
    scanf("%d %d %d", &temp, &M, &K);
    
    int N = 1;
    while(temp > N){ N *= 2;}

    Tree<long long> t(N);
    for(int i=0; i<temp; ++i){
        scanf("%lld", &t.nodes[N+i]);
    }
    t.construct();

    long long a, b, c;
    for(int i=0; i<M+K; ++i){
        scanf("%lld %lld %lld", &a, &b, &c);
        switch(a){
            case 1:
            t.update(b-1, c);
            break;

            case 2:
            printf("%lld\n", t.sum(b-1, c-1, 1, 0, N-1));
            break;
        }
    }
    return 0;
}