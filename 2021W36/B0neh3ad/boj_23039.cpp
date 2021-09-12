/*
    실 전화기
    https://www.acmicpc.net/problem/23039
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    pii edge[N];
    for(int i=0; i<N; ++i){
        int u, v;
        cin >> u >> v;
        if(u > v){ swap(u, v); }
        edge[i] = {u, v};
    }

    pii dia[5] = {{1, 3}, {2, 5}, {1, 4}, {3, 5}, {2, 4}};
    int dia_cnt[5] = {0, };
    int adj_cnt = 0;
    for(int i=0; i<N; ++i)
        for(int j=0; j<5; ++j)
            if(edge[i] == dia[j])
                ++dia_cnt[j];

    for(int i=0; i<5; ++i)
        if(dia_cnt[i] && dia_cnt[(i+1)%5])
            ++adj_cnt;

    int answer = 0;
    if(N == 10)
        answer = -1;
    else if(adj_cnt == 5)
        answer = 2;
    else if(adj_cnt)
        answer = 1;

    cout << answer; 
    return 0;
}