/*
    핑크 플로이드
    https://www.acmicpc.net/problem/6091
*/

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>

using namespace std;

priority_queue<pair<int, pair<int, int>>> pq;
int floyd[1024][1024];
int vis[1024][1024];
vector<priority_queue<int>> MST(1024);
set<int> vertex_set;

int N;

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N-i-1;j++) {
            scanf("%d", &floyd[i][j]);
        }
    }
    for(int i=0;i<N-1;i++) {
        pq.push(make_pair(-floyd[0][i], make_pair(0, i+1)));
    }
    vertex_set.insert(0);
    while(vertex_set.size() < N) {
        
        while((vertex_set.find(pq.top().second.first) != vertex_set.end()) &&
        (vertex_set.find(pq.top().second.second) != vertex_set.end())) {
            //printf("%d %d\n", pq.top().second.first, pq.top().second.second);
            vis[pq.top().second.first][pq.top().second.second] = 1;
            vis[pq.top().second.second][pq.top().second.first] = 1;
            pq.pop();
        }
        int v1 = pq.top().second.first;
        int v2 = pq.top().second.second;
        //printf("<%d %d>\n", v1, v2);
        int selected;
        if(vertex_set.find(v1) == vertex_set.end()) {
            vertex_set.insert(v1);
            selected = v1;
        }
        else if(vertex_set.find(v2) == vertex_set.end()) {
            vertex_set.insert(v2);
            selected = v2;
        }
        MST[v1].push(-v2);
        MST[v2].push(-v1);
        vis[v1][v2] = 1;
        vis[v2][v1] = 1;
        pq.pop();

        for(int i=0;i<selected;i++) {
            if(!vis[i][selected]) {
                //printf("[%d %d]\n", i, selected);
                pq.push(make_pair(-floyd[i][selected-i-1], make_pair(i, selected)));
            }
            else {
                //printf("(%d %d)\n", i, selected);
            }
        }
        for(int i=0;i<N-selected-1;i++) {
            if(!vis[selected][selected+1+i]) {
                //printf("[%d %d]\n", selected, selected+1+i);
                pq.push(make_pair(-floyd[selected][i], make_pair(selected, selected+i+1)));
            }
            else {
                //printf("(%d %d)\n", selected, selected+1+i);
            }
        }
    }
    for(int i=0;i<N;i++) {
        int k = MST[i].size();
        printf("%d ", k);
        for(int j=0;j<k;j++) {
            printf("%d ", -MST[i].top()+1);
            MST[i].pop();
        }
        printf("\n");
    }
}
