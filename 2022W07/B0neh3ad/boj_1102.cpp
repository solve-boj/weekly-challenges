#include <bits/stdc++.h>
using namespace std;

int n;
int c[16][16];
int p, cost[1 << 16];

int sol(int cnt, int st){
    if(cost[st] != -1){ return cost[st]; }
    if(cnt >= p){ return 0; }

    cost[st] = INT_MAX;
    for(int i=0; i<n; ++i){
        if(!(st & (1<<i))){
            int min_cost = INT_MAX;
            for(int j=0; j<n; ++j){
                if(st & (1<<j)){
                    min_cost = min(min_cost, c[n-1-j][n-1-i]);
                }
            }
            cost[st] = min(cost[st], sol(cnt+1, st | (1<<i)) + min_cost);
        }
    }

    return cost[st];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(cost, -1, sizeof(cost));
    cin >> n;

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> c[i][j];
        }
    }

    int init = 0, init_cnt = 0;
    char inp;
    for(int i=0; i<n; ++i){
        cin >> inp;
        init <<= 1;
        init += (inp == 'Y');
        init_cnt += (inp == 'Y');
    }
    cin >> p;

    if(init_cnt == 0 && p > 0) { cout << -1; }
    else { cout << sol(init_cnt, init); }

    return 0;
}