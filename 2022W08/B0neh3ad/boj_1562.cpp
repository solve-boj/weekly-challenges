#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

#define MOD 1000000000

int main(void){
    int n;
    cin >> n;

    int dp[101][10][1 << 10];
    memset(dp, 0, sizeof(dp));

    queue<pii> q;
    for(int i=1; i<=9; ++i){
        dp[1][i][1 << i] = 1;
        q.push(pii(i, 1 << i));
    }

    for(int digit=2; digit<=n; ++digit){
        int qsize = q.size();
        bool visited[10][1 << 10];
        memset(visited, false, sizeof(visited));
        for(int i=0; i<qsize; ++i){
            pii curr = q.front();
            q.pop();
            if(curr.first > 0){
                pii next;
                next.first = curr.first - 1;
                next.second = curr.second | (1 << next.first);

                dp[digit][next.first][next.second] += dp[digit-1][curr.first][curr.second];
                dp[digit][next.first][next.second] %= MOD;
                if(!visited[next.first][next.second]){
                    visited[next.first][next.second] = true;
                    q.push(next);
                }
            }
            if(curr.first < 9){
                pii next;
                next.first = curr.first + 1;
                next.second = curr.second | (1 << next.first);

                dp[digit][next.first][next.second] += dp[digit-1][curr.first][curr.second];
                dp[digit][next.first][next.second] %= MOD;
                if(!visited[next.first][next.second]){
                    visited[next.first][next.second] = true;
                    q.push(next);
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<10; ++i){
        ans += dp[n][i][(1 << 10) - 1];
        ans %= MOD;
    }
    cout << ans;
    return 0;
}