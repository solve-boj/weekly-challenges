#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

const int MAX_COST = 3000001;

int main(void){
    int V, E;
    cin >> V >> E;

    int cost[V][V];
    for(int i=0; i<V; ++i){
        for(int j=0; j<V; ++j){
            cost[i][j] = MAX_COST;
        }
    }
    for(int i=0; i<V; ++i) { cost[i][i] = 0; }
    
    int K;
    cin >> K;
    K--;

    int u, v, w;
    for(int i=0; i<E; ++i){
        cin >> u >> v >> w;
        cost[u-1][v-1] = min(cost[u-1][v-1], w);
    }

    // for(int i=0; i<=K; ++i){
        for(int j=0; j<V; ++j){
            for(int k=0; k<V; ++k){
                if(cost[K][j] > cost[K][k] + cost[k][j]){
                    cost[K][j] = cost[K][k] + cost[k][j];
                }
            }
        }
    // }

    for(int i=0; i<V; ++i){
        cout << ((cost[K][i] < MAX_COST) ? to_string(cost[K][i]) : "INF") << endl;
    }
    return 0;
}