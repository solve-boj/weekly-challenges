/*
    최소 스패닝 트리
    https://www.acmicpc.net/problem/1197
*/

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>

using namespace std;

priority_queue<pair<int, int>> pq;
int V, E;
int cost = 0;
vector<vector<pair<int, int>>> graph(10001);
set<int> vertex_set;

int main() {
    int a, b, c, d;
    scanf("%d %d", &V, &E);
    for(int i=0;i<E;i++) {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(make_pair(c, b));
        graph[b].push_back(make_pair(c, a));
    }
    vertex_set.insert(1);
    for(int i=0;i<graph[1].size();i++) {
        pq.push(make_pair(-graph[1][i].first, -graph[1][i].second));
    }
    while(vertex_set.size() < V) {
        //printf("%d %d\n", cost, pq.size());
        while(vertex_set.find(-pq.top().second) != vertex_set.end()) {
            pq.pop();
        }
        cost += -pq.top().first;
        d = -pq.top().second;
        vertex_set.insert(d);
        pq.pop();
        for(int i=0;i<graph[d].size();i++) {
            pq.push(make_pair(-graph[d][i].first, -graph[d][i].second));
        }

    }

    printf("%d", cost);

}

// keyword: 최소 신장 트리 (Prim)
// 시간복잡도: O(E log V)
/*
idea: 프림 알고리즘 참고(priority queue 사용)
*/