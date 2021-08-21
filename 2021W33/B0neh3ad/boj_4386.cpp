/*
    별자리 만들기
    https://www.acmicpc.net/problem/4386
*/
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int find(int num, int p[]){
    if(num == p[num]){ return num; }
    return (p[num] = find(p[num], p));
}

bool merge(int lhs, int rhs, int p[]){
    lhs = find(lhs, p);
    rhs = find(rhs, p);
    if(lhs == rhs){ return false; }
    p[rhs] = lhs;
    return true;
}

int main(void){
    int n;
    scanf("%d", &n);

    int parent[n];
    vector<vector<double> > adj;
    vector<pair<double, double> > stars;
    double x, y;
    for(int i=0; i<n; ++i){
        scanf("%lf %lf", &x, &y);
        stars.push_back({x, y});
        parent[i] = i; // parent array initialization
    }

    int edge_cnt = 0;
    for(int i=0; i<n-1; ++i){
        for(int j=i+1; j<n; ++j, ++edge_cnt){
            adj.push_back(vector<double>());
            // 거리
            adj[edge_cnt].push_back(sqrt(pow(stars[i].first - stars[j].first, 2) + pow(stars[i].second - stars[j].second, 2)));
            // u, v
            adj[edge_cnt].push_back(i);
            adj[edge_cnt].push_back(j);
        }
    }
    sort(adj.begin(), adj.end());
    
    double min_cost = 0;
    int star_cnt = 0;
    for(auto& edge: adj){
        if(merge(edge[1], edge[2], parent)){
            min_cost += edge[0];
            if(++star_cnt == n-1){ break; }
        }
    }

    printf("%lf", min_cost);
    return 0;
}