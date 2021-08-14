/*
    항체 인식
    https://www.acmicpc.net/problem/22352
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

int n, m;
int before[30][30], after[30][30];

bool eq(int lhs[][30], int rhs[][30]){
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(lhs[i][j] != rhs[i][j]){
                return false;
            }
        }
    }
    return true;
}

void bfs(int y, int x){
    int before_val = before[y][x];
    int after_val = after[y][x];
    queue<pair<int, int> > q;

    before[y][x] = 0;
    q.push({y, x});
    while(!q.empty()){
        int curr_y = q.front().first;
        int curr_x = q.front().second;
        q.pop();

        for(int i=0; i<4; ++i){
            int next_y = curr_y+dy[i];
            int next_x = curr_x+dx[i];
            if(next_y >= 0 && next_y < n && next_x >= 0 && next_x < m){ // 경계 내
                if(before[next_y][next_x] == before_val){ // 미방문
                    before[next_y][next_x] = 0;
                    q.push({next_y, next_x});
                }
            }
        }
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(!before[i][j]){ before[i][j] = after_val; }
        }
    }
}

int main(void){
    cin >> n >> m;

    int start_y = -1, start_x = -1;
    // input
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> before[i][j];
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> after[i][j];
            if(before[i][j] != after[i][j]){ start_y = i; start_x = j; }
        }
    }

    bool flag = true;
    if(start_y >= 0){
        bfs(start_y, start_x);
        if(!eq(before, after)){ flag = false; }
    }

    cout << (flag ? "YES" : "NO");
    return 0;
}
/*
    주어진 두 격자 input을 비교해서
    값이 다르다면 1, 같다면 0을 저장.
    이후 1인 칸을 대상으로 bfs 돌려서 전부 탐색 가능하면(cmps <= 1) true, 아니면(cmps > 1) false
    설령 백신을 놓아서 동일한 값으로 업데이트된 경우(cmps == 0)라도 반례가 되지 않는다.

    1트: 똑같이 component가 1개이더라도 탐색된 칸 수가 다른 경우를 고려하지 않음
    2, 3트: 탐색된 칸 수가 같더라도 그 배치가 다른 경우를 고려하지 않음
    4, 5트: 배치가 같은 경우까지 고려했으나 그 과정에서 논리적 오류 발생.(2 2 / 1 1 1 2 / 2 1 2 1 같은 반례 존재)
    6트: 그냥 다 필요없고 after랑 비교하면 되는 문제... 왜 굳이 compare랑 비교해서 일을 벌렸는지 참..
    7트: start_y > 0이라고 써서 틀린 거 고침..

    7트 만에 성공...
    오늘의 교훈: 필요충분조건 여부가 확실하지 않다면 그냥 문제 그대로 구현하는 편이 속 편하다.
    아니, 그냥 확실하더라도 시간/공간복잡도에서 확실히 이득보는 게 아니라면 그대로 구현하자.
*/