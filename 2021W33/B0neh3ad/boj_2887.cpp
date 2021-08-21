/*
    행성 터널
    https://www.acmicpc.net/problem/2887
*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp_x(vector<int>& lhs, vector<int>& rhs){ return lhs[0] < rhs[0]; }
bool cmp_y(vector<int>& lhs, vector<int>& rhs){ return lhs[1] < rhs[1]; }
bool cmp_z(vector<int>& lhs, vector<int>& rhs){ return lhs[2] < rhs[2]; }

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
    int N;
    scanf("%d", &N);

    vector<vector<int> > tunnels;
    vector<vector<int> > stars;
    int parent[N];
    int x, y, z;
    for(int i=0; i<N; ++i){ parent[i] = i; }
    for(int i=0; i<N; ++i){
        scanf("%d %d %d", &x, &y, &z);
        stars.push_back({x, y, z, i});
    }

    std::sort(stars.begin(), stars.end(), cmp_x);
    for(int i=0; i<N-1; ++i)
        tunnels.push_back({min(min(abs(stars[i][0] - stars[i+1][0]), abs(stars[i][1] - stars[i+1][1])), abs(stars[i][2] - stars[i+1][2])), stars[i][3], stars[i+1][3]});

    std::sort(stars.begin(), stars.end(), cmp_y);
    for(int i=0; i<N-1; ++i)
        tunnels.push_back({min(min(abs(stars[i][0] - stars[i+1][0]), abs(stars[i][1] - stars[i+1][1])), abs(stars[i][2] - stars[i+1][2])), stars[i][3], stars[i+1][3]});
    
    std::sort(stars.begin(), stars.end(), cmp_z);
    for(int i=0; i<N-1; ++i)
        tunnels.push_back({min(min(abs(stars[i][0] - stars[i+1][0]), abs(stars[i][1] - stars[i+1][1])), abs(stars[i][2] - stars[i+1][2])), stars[i][3], stars[i+1][3]});

    std::sort(tunnels.begin(), tunnels.end());

    long long min_cost = 0;
    int cnt = 0;
    for(auto& tunnel: tunnels){
        if(cnt == N-1){ break; }
        if(merge(tunnel[1], tunnel[2], parent)){
            min_cost += tunnel[0];
            ++cnt;
        }
    }

    printf("%lld", min_cost);
    return 0;
}
/*
    O(N^2)에서 컽 당해서 메모리 초과, 런타임 에러 떴음.
    그렇다면 O(N^1.5)든 O(NlogN)이든 줄여야 됨...
    이런 저런 알고리즘 떠올리다가,
    문제의 특성을 생각해보면서 '혹시 쓸데없는 간선이 있을까?' 하고 떠올림.
    그리고 생각난 게 정렬.
    x, y, z성분 중 하나라도 인접한 행성들 간의 간선만 고려해도 OK.
*/