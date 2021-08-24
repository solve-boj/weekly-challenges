/*
    용감한 용사 진수
    https://www.acmicpc.net/problem/14718
*/

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std; 

vector<vector<int>> troops;
int ability[3][100];
int N, K;


int main() {
    int stemp, atemp, itemp;
    int a[3] = {};
    int res = 100000000, cnt = 0;
    scanf("%d %d", &N, &K);
    for(int i=0;i<N;i++) {
        scanf("%d %d %d", &stemp, &atemp, &itemp);
        troops.push_back({stemp, atemp, itemp});
        ability[0][i] = stemp;
        ability[1][i] = atemp;
        ability[2][i] = itemp;
    }

    sort(ability[0], ability[0]+N);
    sort(ability[1], ability[1]+N);
    sort(ability[2], ability[2]+N);

    for(int i=K-1;i<N;i++) {
        for(int j=K-1;j<N;j++) {
            for(int k=K-1;k<N;k++) {
                cnt = 0;
                a[0] = ability[0][i];
                a[1] = ability[1][j];
                a[2] = ability[2][k];
                for(int m=0;m<N;m++) {
                    if(a[0] >= troops[m][0] && a[1]>= troops[m][1]
                    && a[2] >= troops[m][2]) {
                        cnt++;
                        if (cnt == K) break;
                    }
                }
                if (cnt >= K) res = min(res, a[0]+a[1]+a[2]);
            }
        }
    }
    printf("%d", res);
}

// keyword: 정렬, 브루트 포스
// 시간복잡도: O(N^4)
/*
idea: 모든 스탯에 대해 직접 반복하며 모든 경우에 대해 K명 이상을 이길 수 있는지 확인
시간 단축을 위해 이기는 병사 수가 K명이 되면 바로 break
*/