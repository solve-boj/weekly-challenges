/*
    MT
    https://www.acmicpc.net/problem/10265
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n, k, cnt=0, ccnt=0;
vector<int> graph;
vector<bool> vis(1000, false);
vector<bool> done(1000, false);
stack<int> st;
vector<int> cycles, components;
vector<int> containing_cycle(1000, -1);

int memo[1000][1001];
int maxnum = 0;

int dp(int m, int limit) {
    if(memo[m][limit] != -1) return memo[m][limit];
    if(m == 0) {
        if (cycles[0] > limit) return memo[m][limit] = 0;
        if (components[0] < limit) return memo[m][limit] = components[0];
        return memo[m][limit] = limit;
    }
    if(limit == 0) return memo[m][limit] = 0;
    int a = dp(m-1, limit);
    int b = dp(m-1, (limit-cycles[m]>=0)?limit-cycles[m]:0);
    if (limit - b > components[m]) b += components[m];
    else if (limit - b >= cycles[m]) b = limit;
    return memo[m][limit] = (a>b)?a:b;
}


int main() {
    int temp, cycle_begin;
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++) {
        for(int j=0;j<=k;j++) {
            memo[i][j] = -1;
        }
    }
    for(int i=0;i<n;i++) {
        scanf("%d", &temp);
        graph.push_back(temp);
    }
    for(int i=1;i<=n;i++) {
        cnt = 0;
        if(vis[i-1]) continue;
        st.push(i);
        vis[i-1] = true;
        ++ccnt;
        while(!st.empty()) {
            temp = st.top();
            if(!vis[graph[temp-1]-1]) {
                st.push(graph[temp-1]);
                vis[graph[temp-1]-1] = true;
            }
            else {
                if(!done[graph[temp-1]-1]) {
                    cycle_begin = temp;
                    do {
                        temp = graph[temp-1];
                        ++cnt;
                    } while(cycle_begin != temp);
                    cycles.push_back(cnt);
                    components.push_back(cnt);
                    do {
                        temp = graph[temp-1];
                        containing_cycle[temp-1] = cycles.size()-1;
                    } while(cycle_begin != temp);
                };
                st.pop();
                done[temp-1] = true;
                if(containing_cycle[graph[temp-1]-1] != -1 && containing_cycle[temp-1] == -1) {
                    containing_cycle[temp-1] = containing_cycle[graph[temp-1]-1];
                    ++components[containing_cycle[temp-1]];
                }
            }
        }
    }

    printf("%d\n",dp(cycles.size()-1, k));

}