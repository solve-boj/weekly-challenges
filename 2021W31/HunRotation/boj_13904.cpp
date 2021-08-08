/*
    과제
    https://www.acmicpc.net/problem/13904
*/

#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int N, sum=0;
pair<int, int> works[1000];
int workplan[1001] = {};

int main() {
    int a, b;
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d %d", &a, &b);
        works[i] = make_pair(b, a);
    }
    sort(works, works+N);
    reverse(works, works+N);
    for(int i=0;i<N;i++) {
        int j = works[i].second;
        while(j>0 && workplan[j]) j--;
        workplan[j] = works[i].first;
        if(j) sum += works[i].first;
    }
    printf("%d", sum);
}

// keyword: 그리디 알고리즘
// 시간복잡도: O(N^2)
/*
idea: 점수 높은 과제를 무조건 수행할 수 있도록 먼저 탐색
다른 과제도 최대한 같이 수행할 수 있도록 최대한 마감 기한에 맞춰서 수행
*/