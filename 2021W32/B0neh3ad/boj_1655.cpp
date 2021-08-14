/*
    가운데를 말해요
    https://www.acmicpc.net/problem/1655
*/
#include <cstdio>
#include <vector>
#include <queue>

int main(void){
    int n;
    scanf("%d", &n);

    std::priority_queue<int> max_pq; // 작은 원소들
    std::priority_queue<int, std::vector<int>, std::greater<int> > min_pq; // 큰 원소들

    int inp;
    for(int i=0; i<n; ++i){
        scanf("%d", &inp);
        (i%2) ? min_pq.push(inp) : max_pq.push(inp);
        if(i >= 1){ // 여기 i >= 2로 해서 틀렸었다
            if(max_pq.top() > min_pq.top()){
                max_pq.push(min_pq.top());
                min_pq.pop();
                min_pq.push(max_pq.top());
                max_pq.pop();
            }
        }
        printf("%d\n", max_pq.top());
    }
    return 0;
}