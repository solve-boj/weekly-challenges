/*
    연결 요소의 개수
    https://www.acmicpc.net/problem/11724
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N, M, u, v;
vector<vector<int>> graph(1001);
stack<int> st;
vector<bool> vis(1001, false);
int cnt = 0;

int main() {
    int temp;
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<=N;i++) {
        if(vis[i]) continue;
        st.push(i);
        ++cnt;
        vis[i] = true;
        while(!st.empty()) {
            temp = st.top();
            st.pop();
            for(int j: graph[temp]) {
                if(!vis[j]) {
                    st.push(j);
                    vis[j] = true;
                }
            }
        }
    }
    cout << cnt;
}