/*
    도시 분할 계획
    https://www.acmicpc.net/problem/1647
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> graph(1000000);
vector<int> root(100001);
int cnt = 0, ans = 0;

int find(int x) {
    
    if (x == root[x]) {
        return x;
    }
    return root[x] = find(root[x]);
}

void unify(int x, int y) {
    x = find(x);
    y = find(y);
    
    root[x] = y;
}


int main() {
    int a, b, c;
    scanf("%d %d", &N, &M);
    for(int i=0;i<M;i++) {
        scanf("%d %d %d", &a, &b, &c);
        graph[i].push_back(c);
        graph[i].push_back(a);
        graph[i].push_back(b);
    }
    for(int i=1;i<=N;i++) {
        root[i] = i;
    }

    sort(graph.begin(), graph.begin()+M);

    for(int i=0;i<graph.size();i++) { 
        if (cnt == N-2) break;
        if (find(graph[i][1]) != find(graph[i][2])) {
            unify(graph[i][1],  graph[i][2]);
            cnt++;
            ans += graph[i][0];
        }
    }
    printf("%d", ans);
}


// keyword: 최소 신장 트리 (Kruskal)
// 시간복잡도: O(E log E)
/*
idea: 크루스칼 알고리즘으로 최소 신장트리에 사용되는 간선 모두 얻음
이 중 가장 비용 큰 것을 하나 제거
*/