/*
    바이러스
    https://www.acmicpc.net/problem/2606
*/
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

vector<size_t> parent;
vector<size_t> rank;

size_t parent_of(size_t n)
{
    if(parent[n] == 0)
        return n;
    return parent[n] = parent_of(parent[n]);
}

void merge(size_t a,size_t b)
{
    a = parent_of(a);
    b = parent_of(b);

    if(a != b){
        parent[b] = a;
        ::rank[a] += ::rank[b];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    size_t N, M;
    cin >> N >> M;
    parent.resize(N+1);
    ::rank.resize(N+1,1);

    while(M--){
        size_t a,b;
        cin >> a >> b;
        merge(a,b);
    }

    cout << ::rank[parent_of(1)] - 1;
}