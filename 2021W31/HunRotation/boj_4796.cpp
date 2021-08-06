/*
    캠핑
    https://www.acmicpc.net/problem/4796
    실버4 이하
*/

#include <cstdio>
#include <algorithm>

using namespace std;

long long L, P, V;

int main() {
    long long cnt = 1;
    scanf("%lld %lld %lld", &L, &P, &V);
    
    while (L * P * V) {   
        printf("Case %lld: %lld\n", cnt++, (long long) V/P*L + min(V%P, L));
        scanf("%lld %lld %lld", &L, &P, &V);
    }
}

// keyword: 그리디 알고리즘
// 시간복잡도: O(1)
/*
idea: 무조건 캠핑하는 날을 앞에 잡는게 이득, 즉 캠핑하는 날 L일, 안하는 날 P-L일 반복
*/