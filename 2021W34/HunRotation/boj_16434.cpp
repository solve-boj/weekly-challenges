/*
    드래곤 앤 던전
    https://www.acmicpc.net/problem/16434
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int N, H_atk;
int dungeon[123456][3];

bool fight(long long maxHP, long long atk) {
    int t, a, h;
    long long curHP = maxHP;
    for(int i=0;i<N;i++) {
        //printf("<%d> %lld %lld\n", i, curHP, atk);
        t = dungeon[i][0];
        a = dungeon[i][1];
        h = dungeon[i][2];
        if(t==1) {
            if((curHP - 1) / a + 1 >= (h - 1) / atk + 1) {
                curHP -= a*((h-1)/atk);
                continue;
            }
            else return false;
        }
        else if(t==2) {
            atk += a;
            curHP = min(maxHP, curHP + h);
        }
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &H_atk);
    for(int i=0;i<N;i++) {
        scanf("%d %d %d", &dungeon[i][0], &dungeon[i][1], &dungeon[i][2]);
    }
    long long mid;
    bool win;
    long long l=0, r=999999999999999999LL;
    while(l+1 < r) {
        //printf("%lld %lld\n", l, r);
        mid = (l+r)/2;
        win = fight(mid, H_atk);
        if(win) r = mid;
        else l = mid;
    }
    printf("%lld", r);
}


// keyword: 이분 탐색
// 시간복잡도: O(N log N)
/*
idea: mid 값이 임의로 설정한 두 공유기가 가지는 최소 거리 -> 이 값을 최대로 만들어야 함
*/