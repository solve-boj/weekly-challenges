/*
    Arctic Network
    https://www.acmicpc.net/problem/4343
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
    int N;
    scanf("%d", &N);
    for(int t=0; t<N; ++t){
        int S, P;
        scanf("%d %d", &S, &P);

        double x, y;
        vector<vector<double> > adj(P*(P-1)/2);
        vector<pair<double, double> > towns(P);
        int parent[P];
        for(int i=0; i<P; ++i){
            scanf("%lf %lf", &x, &y);
            towns[i] = {x, y};
            parent[i] = i;
        }

        int link_cnt = 0;
        for(int i=0; i<P-1; ++i){
            for(int j=i+1; j<P; ++j, ++link_cnt){
                adj[link_cnt].push_back(sqrt(pow(towns[i].first - towns[j].first, 2) + pow(towns[i].second - towns[j].second, 2)));
                adj[link_cnt].push_back(i);
                adj[link_cnt].push_back(j);
            }
        }
        sort(adj.begin(), adj.end());
        double max_d = 0;
        int valid_cnt = 0;
        for(auto& link: adj){
            if(valid_cnt == P-S){ break; }
            if(merge(link[1], link[2], parent)){
                max_d = link[0];
                ++valid_cnt;
            }
        }

        printf("%.2lf\n", max_d);
    }
    return 0;
}
/*
    148ms... 왜 이리 느리지???
*/