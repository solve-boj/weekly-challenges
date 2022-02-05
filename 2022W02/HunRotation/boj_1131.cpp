/*
    요세푸스 문제
    https://www.acmicpc.net/problem/1158
*/

#include <cstdio>
#include <list>

using namespace std;

int N, K;
list<int> li, result;
int main() {
    scanf("%d %d", &N, &K);
    for(int i=1;i<=N;i++) {
        li.push_back(i);
    }
    int cnt = 1;
    auto iter = li.begin();
    while(!li.empty()) {
        if(cnt % K == 0) {
            result.push_back(*iter);
            iter = li.erase(iter);
        }
        else iter++;
        if(iter == li.end()) {
            iter = li.begin();
        }
        cnt++;
    }
    printf("<");
    auto result_iter = result.begin();
    for(int i=0;i<N;i++) {
        printf("%d", *(result_iter++));
        if(i<N-1) printf(", ");
    }
    printf(">");

}