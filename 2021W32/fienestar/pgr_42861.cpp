/*
    섬 연결하기
    https://programmers.co.kr/learn/courses/30/lessons/42861
*/
#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> costs)
{
    sort(costs.begin(), costs.end(), [](auto& a, auto& b) {
        return a[2] < b[2];
    });
    
    vector<size_t> parent(n);
    for(size_t i=0; i!=n; ++i)
        parent[i] = i;
    
    function<size_t(size_t)> root = [&](size_t i) {
        if(parent[i] == i)
            return i;
        else
            return parent[i] = root(parent[i]);
    };
    
    size_t answer = 0;
    for(auto& cost:costs){
        cost[0] = root(cost[0]);
        cost[1] = root(cost[1]);
        if(cost[0] != cost[1]) {
            answer += cost[2];
            parent[cost[0]] = cost[1];
        }
    }
    
    return answer;
}