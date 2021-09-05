/*
    팀 프로젝트
    https://www.acmicpc.net/problem/9466
*/

#include <cstdio>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

int T, N;

int selected[100001];
bool visited[100001];
bool finished[100001];
stack<int> st;

int main() {
    scanf("%d", &T);
    int temp, cycle_member;
    for(int n=0;n<T;n++) {
        scanf("%d", &N);
        int answer = N;
        for(int i=1;i<=N;i++) {
            scanf("%d", selected+i);
        }
        
        for(int i=1;i<=N;i++) {
            if(!visited[i]) {
                st.push(i);
                visited[i] = true;
                while(!st.empty()) {
                    temp = st.top();
                    
                    //printf("[%d]\n", temp);
                    
                    if(visited[selected[temp]] && !finished[selected[temp]]) {
                        cycle_member = temp;
                        //printf("{%d}\n", cycle_member);
                        answer--;
                        cycle_member = selected[cycle_member];
                        while(cycle_member != temp) {
                            //printf("{%d}\n", cycle_member);
                            answer--;
                            cycle_member = selected[cycle_member];
                        }
                    }

                    
                    if(!visited[selected[temp]]) {
                        st.push(selected[temp]);
                        visited[selected[temp]] = true;
                    }
                    else {
                        st.pop();
                        finished[temp] = true;
                    }
                    
                    
                }
                //printf("^%d\n", answer);
            }            
        }
        printf("%d\n", answer);
        fill(visited+1, visited+N+1, false);
        fill(finished+1, finished+N+1, false);
    }
}

// keyword: DFS
// 시간복잡도: O(N)
/*
idea: visited - 방문한 점, finished - 옆 지점 탐색을 모두 끝낸 점
visited에 포함되어 있으면서 finished에 포함되지 않은 점이 옆 점일 경우 사이클 탐색을 시작함
사이클에 포함된 원소의 수만큼 answer에서 차감 
*/