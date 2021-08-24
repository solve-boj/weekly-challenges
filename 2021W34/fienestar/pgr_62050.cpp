/*
    지형 이동
    https://programmers.co.kr/learn/courses/30/lessons/62050
*/
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> land, int height)
{
    const size_t N = land.size();
    priority_queue<tuple<int, size_t, size_t>> pq;
    vector<size_t> parent(N*N);
    
    for(size_t i=0; i!=N*N; ++i)
        parent[i] = i;
    
    auto idx = [&] (size_t i, size_t j) { return i*N+j; };
    function<size_t(size_t)> root = [&](size_t i) {
        if(parent[i] == i)
            return i;
        else
            return parent[i] = root(parent[i]);
    };
    
    for(size_t i=0; i!=N; ++i)
        for(size_t j=0; j!=N; ++j)
            for(size_t k=0; k!=2; ++k) {
                static constexpr int di[] = {1,0};
                static constexpr int dj[] = {0,1};
                
                size_t mi = i + di[k];
                size_t mj = j + dj[k];
                
                if(mi >= N || mj >= N)
                    continue;
                
                int diff = abs(land[mi][mj] - land[i][j]);
                size_t a = idx(mi, mj);
                size_t b = idx(i, j);
                
                if(diff <= height)
                    parent[root(a)] = root(b);
                else
                    pq.emplace(-diff, a, b);
            }
    
    size_t ans = 0;
    while(!pq.empty())
    {
        auto[cost, a, b] = pq.top();
        pq.pop();
        
        a = root(a);
        b = root(b);
        
        if(a == b)
            continue;
        
        ans -= cost;
        parent[a] = b;
    }
    
    return ans;
}
/*
    단지 번호 대신 인덱스를 사용합시다.
*/
