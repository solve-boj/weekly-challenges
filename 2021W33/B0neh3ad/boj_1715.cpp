/*
    카드 정렬하기
    https://www.acmicpc.net/problem/1715
*/
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main(void){
    int n;
    scanf("%d", &n);

    int size = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0; i<n; ++i){
        scanf("%d", &size);
        pq.push(size);
    }

    int answer = 0;
    for(int i=1; i<n; ++i){
        int new_size = 0;
        new_size += pq.top();
        pq.pop();
        new_size += pq.top();
        pq.pop();
        
        answer += new_size;
        pq.push(new_size);
    }

    printf("%d", answer);
    return 0;
}
/*
    핵심은 "크기가 큰 카드뭉치의 비교횟수를 최소화"한다는 것!
    초기 상태 기준으로만 생각하면 안 되고,
    매 비교 때마다 생각해야 한다!
*/