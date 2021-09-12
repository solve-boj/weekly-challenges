/*
    자연수 색칠하기
    https://www.acmicpc.net/problem/23048
*/


#include <cstdio>
#include <algorithm>

using namespace std;

int N, color=1;
int checked[500001];

int main() {
    scanf("%d", &N);
    checked[1] = 1;
    for(int i=2;i<=N;i++) {
        if(!checked[i]) {
            color++;
            for(int j=i;j<=N;j+=i) {
                if(!checked[j]) checked[j] = color;
            }
        }
    }
    printf("%d\n", color);
    for(int i=1;i<=N;i++) {
        printf("%d ", checked[i]);
    }

}