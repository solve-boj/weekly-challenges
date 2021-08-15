/*
    중앙값 구하기
    https://www.acmicpc.net/problem/2696
*/
#include <cstdio>
#include <vector>
#include <queue>

int main(void){
    int t;
    scanf("%d", &t);

    int m;
    for(int i=0; i<t; ++i){
        std::priority_queue<int> max_pq;
        std::priority_queue<int, std::vector<int>, std::greater<int> > min_pq;
        scanf("%d", &m);

        int elem[m];
        for(int j=0; j<m; ++j){ scanf("%d", &elem[j]); }

        printf("%d\n", m/2+1);
        for(int j=1; j<=m; ++j){
            (j%2) ? max_pq.push(elem[j-1]) : min_pq.push(elem[j-1]);
            if(j > 1){
                if(max_pq.top() > min_pq.top()){
                    max_pq.push(min_pq.top());
                    min_pq.pop();
                    min_pq.push(max_pq.top());
                    max_pq.pop();
                }
            }
            if(j%2){ printf("%d ", max_pq.top()); }
            if(j%20 == 0 || j == m){ printf("\n"); }
        }
    }
    return 0;
}
/*
    출력 형식을 잘 맞추자
*/