/*
    섬 연결하기
    https://programmers.co.kr/learn/courses/30/lessons/42861
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parents;

int find(int x) {
    if(parents[x] == x) return x;
    else return parents[x] = find(parents[x]);
}

void unify(int x, int y) {
    x = find(x);
    y = find(y);
    parents[y] = x;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int cnt = 0;
    
    for(int i=0;i<n;i++) {
        parents.push_back(i);
    }
    for(int i=0;i<costs.size();i++) {
        swap(costs[i][0], costs[i][2]);
        if (costs[i][1] > costs[i][2]) {
            swap(costs[i][1], costs[i][2]);
        }
    }

    sort(costs.begin(), costs.end());

    for(int i=0;i<costs.size();i++) {
        if (cnt==n-1) break;
        if(find(costs[i][1]) != find(costs[i][2])) {
            answer += costs[i][0];
            unify(costs[i][1], costs[i][2]);
            cnt++;
        }
    }

    return answer;
}

// keyword: 최소 신장 트리 (Kruskal)
// 시간복잡도: O(E log E)
/*
idea: 크루스칼 알고리즘 참고
*/