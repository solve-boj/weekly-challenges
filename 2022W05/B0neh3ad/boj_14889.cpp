#include <bits/stdc++.h>
using namespace std;
#define MAX_VAL 1000000

int n;
int abt[20][20];

bool member[20];
int start, link;
int ans = MAX_VAL;

// cur: 현재 포함여부를 고려하는 멤버의 idx, cnt: 현재 start팀 멤버 수
void sol(int cur, int cnt){
    if(cnt == n/2){
        ans = min(ans, abs(start-link));
        return;
    }

    if(cur == n){ return; }

    member[cur] = true;
    for(int i=0; i<n; ++i){
        if(member[i]){
            start += abt[i][cur] + abt[cur][i];
        }
        else {
            link -= abt[i][cur] + abt[cur][i];
        }
    }
    sol(cur+1, cnt+1);
    for(int i=0; i<n; ++i){
        if(member[i]){
            start -= abt[i][cur] + abt[cur][i];
        }
        else {
            link += abt[i][cur] + abt[cur][i];
        }
    }
    member[cur] = false;
    sol(cur+1, cnt);
}

int main(void){
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> abt[i][j];
            link += abt[i][j];
        }
    }
    fill(member, member+20, false);
    sol(0, 0);
    cout << ans;
    return 0;
}

// 능력치를 빼는 과정이 좀 복잡하므로
// 이 경우에는 매개변수로 넘기는 게 더 효율적일 수 있다