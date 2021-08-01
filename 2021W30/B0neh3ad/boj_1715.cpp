/*
    카드 정렬하기
    https://www.acmicpc.net/problem/1715
*/
#include <cstdio>
#include <queue>

int main(void){
    int N;
    scanf("%d", &N);

    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
    long long temp;
    for(int i=0; i<N; ++i){
        scanf("%lld", &temp);
        pq.push(temp);
    }

    long long ans = (-1) * pq.top();
    for(int i=0; i<N; ++i){
        ans += pq.top() * (N-i);
        pq.pop();
    }

    printf("%lld", ans);

    return 0;
}