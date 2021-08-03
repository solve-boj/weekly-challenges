/*
    구간 곱 구하기
    https://www.acmicpc.net/problem/11505
*/
#include <cstdio>
#include <vector>

template<typename T>
class Tree{
public:;
    int size;
    std::vector<T> nodes;

    Tree(): size(0){}
    Tree(int n): size(2*n){
        nodes.resize(2*n, 1);
    }

    T mul(int L, int R, int nodeNum, int nodeL, int nodeR){
        if(R < nodeL || nodeR < L){ return 1; }
        if(L <= nodeL && nodeR <= R){ return nodes[nodeNum]; }
        int mid = (nodeL + nodeR) / 2;
        return (mul(L, R, nodeNum*2, nodeL, mid) * mul(L, R, nodeNum*2+1, mid+1, nodeR)) % 1000000007;
    }

    void update(int i, int val){
        i += size/2;
        nodes[i] = val;
        while(i > 1){
            i /= 2;
            nodes[i] = (nodes[i*2] * nodes[i*2+1]) % 1000000007;
        }
    }

    void construct(){
        for(int i=size/2-1; i>0; --i){
            nodes[i] = (nodes[i*2] * nodes[i*2+1]) % 1000000007;
        }
    }
};

int main(void){
    int temp, M, K;
    scanf("%d %d %d", &temp, &M, &K);

    int N = 1;
    while(temp > N){ N *= 2; }
    Tree<long long> t(N);
    for(int i=0; i<temp; ++i){
        scanf("%lld ", &t.nodes[N+i]);
    }
    t.construct();

    int a, b;
    long long c;
    for(int i=0; i<M+K; ++i){
        scanf("%d %d %lld", &a, &b, &c);
        switch(a){
            case 1:
            t.update(b-1, c);
            break;

            case 2:
            printf("%lld\n", t.mul(b-1, c-1, 1, 0, N-1));
            break;
        }
    }
    return 0;
}

/*
    scanf 사용 시 & 빼먹지 말고
    대소관계 잘 생각하고
*/