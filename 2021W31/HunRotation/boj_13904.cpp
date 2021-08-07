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