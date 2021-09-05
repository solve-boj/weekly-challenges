/*
    유기농 배추
    https://www.acmicpc.net/problem/1012
*/

#include <cstdio>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

int T, M, N, K, cnt=0;
pair<int, int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
set<pair<int, int>> pos;
set<pair<int, int>> visited;
stack<pair<int, int>> st;

int main() {
    scanf("%d", &T);
    int x, y;
    pair<int, int> temp;
    int newx, newy;
    for(int n=0;n<T;n++) {
        cnt = 0;
        scanf("%d %d %d", &M, &N, &K);
        for(int i=0;i<K;i++) {
            scanf("%d %d", &x, &y);
            pos.insert({x, y});
        }
        for(auto it=pos.begin();it!=pos.end();++it) {
            if(visited.find(*it) == visited.end()) {
                ++cnt;
                /*
                printf("[%d]\n", cnt);
                for(auto k=pos.begin();k!=pos.end();++k) {
                    printf("%d %d\n", (*k).first, (*k).second);
                }
                */
                st.push(*it);
                while(!st.empty()) {
                    temp = st.top();
                    st.pop();
                    visited.insert(temp);
                    for(int i=0;i<4;i++) {
                        newx = temp.first + dir[i].first;
                        newy = temp.second + dir[i].second;
                        if(0<=newx && newx<M && 0<=newy && newy<N 
                        && pos.find({newx, newy}) != pos.end() &&
                        visited.find({newx,newy}) == visited.end()) {
                            st.push({newx, newy});
                        }    
                    }
                }
            }
        }
        printf("%d\n", cnt);
        pos.clear();
        visited.clear();
    }
}

// keyword: DFS (or BFS)
// 시간복잡도: O(N^2)
/*
idea: 위치를 모두 set에 저장하고 set에서 방문하지 않은 점을 하나씩 스택에 넣어
여러 번 DFS를 진행함
한 번 방문한 점의 위치는 cisited라는 다른 set에 보관
*/