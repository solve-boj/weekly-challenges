/*
    최소 힙
    https://www.acmicpc.net/problem/1927
*/
#include <cstdio>
#include <vector>
#include <queue>

int main(void){
    int N;
    scanf("%d", &N);

    std::priority_queue<long long, std::vector<long long>, std::greater<long long> > pq;
    long long temp;
    for(int i=0; i<N; ++i){
        scanf("%lld", &temp);
        if(temp){ pq.push(temp); }
        else{
            if(pq.size()){ printf("%lld\n", pq.top()); pq.pop(); }
            else{ printf("0\n"); }
        }
    }

    return 0;
}