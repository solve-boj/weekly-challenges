/*
    회의준비
    https://www.acmicpc.net/problem/2610
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e7;

int find(int num, int p[]){
    if(num == p[num]){ return num; }
    p[num] = find(p[num], p);
    return p[num];
}

void merge(int lhs, int rhs, int p[]){
    lhs = find(lhs, p);
    rhs = find(rhs, p);
    if(lhs == rhs){ return; }
    p[rhs] = lhs;
}

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);

    int link[N][N];
    int parent[N];
    int u, v;
    for(int i=0; i<N; ++i){
        fill(link[i], link[i]+N, INF);
        link[i][i] = 0;
        parent[i] = i;
    }

    
    for(int i=0; i<M; ++i){
        scanf("%d %d", &u, &v);
        if(u != v){
            link[u-1][v-1] = link[v-1][u-1] = 1;
            merge(u-1, v-1, parent);
        }
    }

    for(int k=0; k<N; ++k){
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                if(link[i][j] > link[i][k] + link[k][j]){
                    link[i][j] = link[i][k] + link[k][j];
                }
            }
        }
    }
    
    // 각 위원회 별로 [대표][의사전달시간 최댓값 중 최솟값]를 저장하는 길이 N 배열 만들기
    // 초기값은 INF로 하고, 따라서 마지막에 위원회 대표 출력할 때 INF인 index는 건너 뛰도록
    pair<int, int> ans[N];
    for(int i=0; i<N; ++i){
        ans[i] = {INF, INF};
        find(i, parent);
    }
    for(int i=0; i<N; ++i){
        int max_time = 0;
        for(int j=0; j<N; ++j){
            // 최소한 link[i][i]는 아래 조건을 만족
            if(link[i][j] < INF){
                max_time = max(max_time, link[i][j]);
            }
        }
        // 위원회는 parent[i] 값으로 구분 가능.
        if(ans[parent[i]].second > max_time){
            ans[parent[i]].first = i+1;
            ans[parent[i]].second = max_time;
        }
    }

    sort(ans, ans+N);

    int cnt = 0;
    while(cnt < N){
        if(ans[cnt].second >= INF){ break; }
        ++cnt;
    }

    printf("%d\n", cnt);
    for(int i=0; i<cnt; ++i){
        printf("%d\n", ans[i].first);
    }

    return 0;
}
/*
    이 문제는 가중치가 따로 있는 게 아니라서 bfs로도 최단 거리를 구할 수 있다.

    계속 틀린 이유: find를 1번씩 더 돌려줘야 한 컴포넌트가 완전히 동일한 노드를 루트로 가리키게 된다.
*/