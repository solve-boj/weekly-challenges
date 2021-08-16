/*
    박스 채우기
    https://www.acmicpc.net/problem/1493
*/

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
int length, width, height, N;
vector<long long> cubes(20);
vector<long long> requires(20);

vector<long long> f(int l, int w, int h) {
    vector<long long> req(20);
    //printf("<%d %d %d>\n", l,w,h);
    if ((long long)l*w*h == 0) {
        return req;
    }
    int m = (int) min(min(log(l+0.1) / log(2), log(w+0.1) / log(2)), log(h+0.1) / log(2));
    int mp = (int) (pow(2, m) + 0.1);
    //printf("%d %d %d %d\n",mp,l/mp,w/mp,h/mp);
    vector<long long> part1(20), part2(20), part3(20);
    if (mp < h) {
        part1 = f(l,w,h%mp);
    }
    if (mp < w) {
        part2 = f(l, w%mp, h/mp*mp);
    }
    if (mp < l) {
        part3 = f(l%mp, w/mp*mp, h/mp*mp);
    }
    for(int i=0;i<req.size();i++) {
        req[i] = part1[i] + part2[i] + part3[i];
        if (i==m) req[i] += (long long)(l/mp) * (w/mp) * (h/mp);
    }
    /*
    for(int i=0;i<req.size();i++) {
        printf("%lld ", req[i]);
    }
    printf("\n");
    */
    return req;
}

int main() {
    int a, b, cnt = 0;
    scanf("%d %d %d", &length, &width, &height);
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d %d", &a, &b);
        cubes[a] = b;
    }
    requires = f(length, width, height);
    /*
    for(int i=0;i<requires.size();i++) {
        printf("%lld ", requires[i]);
    }
    printf("\n");
    */
    for(int i=19;i>0;i--) {
        if (cubes[i] < requires[i]) {
            cnt += cubes[i];
            requires[i-1] += 8 * (requires[i] - cubes[i]);
        }
        else {
            cnt += requires[i];
        }
    }
    if (cubes[0] < requires[0]) {
            cnt = -1;
    }
    else {
        cnt += requires[0];
    }
    
    printf("%d", cnt);
}

// keyword: 그리디 알고리즘, 분할 정복
// 시간복잡도: O(3^N)
/*
idea: 남은 큐브 공간에 들어갈 수 있는 최대 정육면체 구함, 남은 공간을 3개로 분할해 같은 작업 시행
*/