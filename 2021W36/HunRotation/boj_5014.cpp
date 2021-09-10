/*
    스타트링크
    https://www.acmicpc.net/problem/5014
*/

#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int F, S, G, U, D;
queue<pair<int, int>> q;
bool vis[1000001];

int main() {
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    q.push({S, 0});
    vis[S] = true;
    int cur, num, ans = -1;
    while(!q.empty()) {
        cur = q.front().first;
        num = q.front().second;
        q.pop();
        if (cur == G) {
            ans = num;
            break;
        }
        if(U+cur <= F && !vis[U+cur]) {
            q.push({U+cur, num+1});
            vis[U+cur] = true;
        }
        if(cur-D >= 1 && !vis[cur-D]){
            q.push({cur-D, num+1});
            vis[cur-D] = true;
        }
    }
    if(ans == -1) {
        printf("use the stairs");
    }
    else {
        printf("%d", ans);
    }
}

// keyword: BFS
// 시간복잡도: O()
/*
idea: queue 원소 구조 - {현재 층, 현재 층에 도달하는데 필요한 최소 버튼 누르는 횟수}
*/