/*
    섬 연결하기
    https://programmers.co.kr/learn/courses/30/lessons/42861
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int>& lhs, const vector<int>& rhs){ return lhs[2] < rhs[2]; }

class UnionFind{
public:
    int ufsize;
    vector<int> p;

    UnionFind(): ufsize(0){}
    UnionFind(int n): ufsize(n){
        p.resize(n, -1);
    }

    int find(int node){ // 부모 찾기
        if(p[node] == -1){ return node; }
        p[node] = find(p[node]); // 갱신
        return p[node];
    }

    void merge(int p1, int p2){ // "둘의 부모를" 합치기
        // 이거 p1, p2로 안 해서 틀림
        p1 = find(p1);
        p2 = find(p2);
        if(p1 == p2){ return; }
        p[p1] = p2;
    }
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), cmp); // 가중치 오름차순 정렬
    
    UnionFind uf(n);
    for(auto& edge: costs){
        if(uf.find(edge[0]) != uf.find(edge[1])){ // 두 정점이 연결되지 않았다면
            answer += edge[2];
            uf.merge(edge[0], edge[1]);
        }
    }

    return answer;
}

int main(void){
    cout << solution(4, {{0,1,1},{1,2,2},{0,2,1},{0,3,1},{3,2,2}}) << endl;
    return 0;
}

/*
    처음에는 외판원 문제..인 줄 알았으나
    그거는 '순회' 경로를 찾는 거고 이거는 단순히 연결만 되면 OK라 다른 문제임을 깨달았다.
    암만 대가리를 굴려도 괴상한 시간복잡도의 알고리즘만 생각났고
    그러던 중 간선을 가중치 오름차순으로 정렬하면 어떨까 하는 생각이 났다.
    근데, 앞선 발상 과정에서 나온 아이디어 중
    '간선 추가 시 cycle이 형성되면 반드시 최적해가 아니다'는 증명이 가능했는데
    그래서 이걸 어떻게 검사해야 되느냐가 문제였다.
    결국 여기까지만 생각을 마무리하고 비슷한 알고리즘을 찾아보다가 크루스칼 알고리즘을 알게 되어 이를 이용했다.

    풀면서 느낀 건데 이제보니 완전 union find 문제네??

    1트: 어쨌든 크루스칼 알고리즘으로 바로 컽!
*/