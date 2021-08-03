/*
    커피숍2
    https://www.acmicpc.net/problem/1275
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
    for(int i=0; i<N; ++i){
        scanf("%lld", &t.nodes[tsize+i]);
    }
    t.construct();

    int x, y, a;
    long long b;
    for(int i=0; i<Q; ++i){
        scanf("%d %d %d %lld", &x, &y, &a, &b);
        printf("%lld\n", (x>y) ? t.sum(y-1, x-1, 1, 0, tsize-1) : t.sum(x-1, y-1, 1, 0, tsize-1));
        t.update(a-1, b);
    }
    return 0;
}
/*
    tree construct 해주는 거 종종 까먹는다... 조심!
    그리고 이 문제는 BIT 이용 풀이도 있는 거 같으니까 배운 다음에 다시 풀어보자.
*/