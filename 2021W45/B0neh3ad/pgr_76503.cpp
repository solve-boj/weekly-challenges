/*
    모두 0으로 만들기
    https://programmers.co.kr/learn/courses/30/lessons/76503?language=cpp
*/

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

long long solution(vector<int> a, vector<vector<int>> edges) {
    int n = a.size();

    vector<long long> nodes(n);
    vector<int> deg(n);
    vector<vector<int>> adj(n);
    long long answer = 0;

    // not valid case: sum != 0
    long long sum = 0;
    for(auto& w: a){
        sum += w;
    }
    if(sum){ return -1; }

    // set nodes
    for(int i=0; i<n; ++i){ nodes[i] = a[i]; }

    // set adjacent nodes, degree vector
    for(auto& edge: edges){
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++deg[u], ++deg[v];
    }

    // init leaf nodes queue
    queue<int> leafs;
    for(int i=0; i<n; ++i){
        if(deg[i] == 1){ 
            leafs.push(i);
        }
    }

    while(!leafs.empty()){
        int leaf = leafs.front();
        leafs.pop();

        for(auto& node: adj[leaf]){
            if(deg[node] > 0){ // if adj node is not leaf
                // make the weight of leaf to 0
                // by move weight to adj node
                nodes[node] += nodes[leaf];
                answer += abs(nodes[leaf]);
                nodes[leaf] = 0;

                // set deg of leaf and adj node
                deg[leaf] = 0;
                deg[node] -= 1;

                // if adj become leaf then push to leaf queue
                if(deg[node] == 1){ leafs.push(node); }
                break;
            }
        }
    }

    return answer;
}

/*
    greedy 문제.
    leaf node의 가중치를 adj node에 더하는 걸 반복하면 된다.
    시간복잡도: O(n)보다는 좀 클거 같은데..
*/