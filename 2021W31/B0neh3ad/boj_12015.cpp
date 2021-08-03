/*
    가장 긴 증가하는 부분 수열 2
    https://www.acmicpc.net/problem/12015
*/
#include <cstdio>
#include <vector>
#include <algorithm>

const int MAX_SIZE = 3000000;

int nodes[MAX_SIZE];

bool cmp(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs){
    return (lhs.first == rhs.first) ? (lhs.second > rhs.second) : (lhs.first < rhs.first);
}

class Tree{
public:
    int size;

    Tree(): size(0){}
    Tree(int n): size(2*n){}

    void update(int i){
        i += size/2;
        nodes[i] = findMax(0, i - size/2, 1, 0, size/2 - 1) + 1;

        while(i > 1){
            i /= 2;
            nodes[i] = std::max(nodes[i*2], nodes[i*2+1]); 
        }
    }

    int findMax(int L, int R, int nodeNum, int nodeL, int nodeR){
        if(R < nodeL || nodeR < L){ return 0; }
        if(L <= nodeL && nodeR <= R){ return nodes[nodeNum]; }
        int mid = (nodeL + nodeR) / 2;
        return std::max(findMax(L, R, nodeNum*2, nodeL, mid), findMax(L, R, nodeNum*2+1, mid+1, nodeR));
    }
};

int main(void){
    int N;
    scanf("%d", &N);

    std::pair<int, int> A[N];
    for(int i=0; i<N; ++i){
        scanf("%d", &A[i].first);
        A[i].second = i;
    }
    std::sort(A, A+N, cmp);

    int tsize = 1;
    while(tsize < N){ tsize *= 2; }

    Tree t(tsize);
    for(int i=0; i<N; ++i){
        t.update(A[i].second);
    }

    printf("%d", nodes[1]);
    return 0;
}

/*
dp로도 (O(n^2))에) 풀 수 있고
이분탐색으로도 풀 수 있고
세그 트리로도 풀 수 있는 문제

나머지 두 방법으로도 풀어보자
*/