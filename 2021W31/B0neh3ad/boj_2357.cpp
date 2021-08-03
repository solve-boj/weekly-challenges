/*
    최솟값과 최댓값
    https://www.acmicpc.net/problem/2357
*/
#include <cstdio>
#include <vector>
#include <algorithm>

const long long MAX_VALUE = 1000000001;

class Tree{
public:
    int size;
    std::vector<long long> max_nodes;
    std::vector<long long> min_nodes;

    Tree(): size(0){}
    Tree(int n): size(2*n){
        max_nodes.resize(2*n, 0);
        min_nodes.resize(2*n, MAX_VALUE);
    }

    std::pair<long long, long long> cal(int L, int R, int nodeNum, int nodeL, int nodeR){
        if(R < nodeL || nodeR < L){ return {0, MAX_VALUE}; }
        if(L <= nodeL && nodeR <= R){ return {max_nodes[nodeNum], min_nodes[nodeNum]}; }

        int mid = (nodeL + nodeR) / 2;
        std::pair<long long, long long> lc = cal(L, R, nodeNum*2, nodeL, mid);
        std::pair<long long, long long> rc = cal(L, R, nodeNum*2+1, mid+1, nodeR);
        
        return {std::max(lc.first, rc.first), std::min(lc.second, rc.second)};
    }

    void construct(){
        for(int i=size/2-1; i>0; --i){
            max_nodes[i] = std::max(max_nodes[i*2], max_nodes[i*2+1]);
            min_nodes[i] = std::min(min_nodes[i*2], min_nodes[i*2+1]);
        }
    }
};
int main(void){
    int temp, M;
    scanf("%d %d", &temp, &M);

    int N = 1;
    while(temp > N){ N *= 2; }

    Tree t(N);
    for(int i=0; i<temp; ++i){
        scanf("%lld", &t.max_nodes[N+i]);
        t.min_nodes[N+i] = t.max_nodes[N+i];
    }
    t.construct();

    int a, b;
    std::pair<long long, long long> ans;
    for(int i=0; i<M; ++i){
        scanf("%d %d", &a, &b);
        ans = t.cal(a-1, b-1, 1, 0, N-1);
        printf("%lld %lld\n", ans.second, ans.first);
    }
    return 0;
}
/*
    vector 말고 걍 배열 쓰면 안 되나
*/