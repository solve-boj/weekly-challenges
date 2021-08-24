/*
    색종이 만들기
    https://www.acmicpc.net/problem/2630
*/

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int board[128][128];

vector<int> f(int x, int y, int size) {
    vector<int> v = {0, 0};
    if(size == 1) {
        v[board[x][y]] = 1;
        return v;
    }
    vector<int> flag = {1, 1};
    for(int i=x;i<x+size;i++) {
        for(int j=y;j<y+size;j++) {
            flag[1 - board[i][j]] = 0;
        }
    }
    for(int i:{0, 1}) {
        if(flag[i]) {
            v[i] = 1;
            return v;
        }
    }
    for(int i:{x, x+size/2}) {
        for(int j:{y, y+size/2}) {
            vector<int> w = f(i, j, size/2);
            v[0] += w[0];
            v[1] += w[1];
        }
    }
    return v;
    
}

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            scanf("%d", &board[i][j]);
        }
    }
    vector<int> res = f(0, 0, N);
    printf("%d\n%d", res[0], res[1]);
}

// keyword: 분할 정복
// 시간복잡도: O(N^2 log N)
/*
idea: 숫자 통일되어 있으면 {1, 0} 또는 {0, 1} return
그렇지 않으면 4개 부분으로 나눠 얻은 값의 성분별 합을 return
*/