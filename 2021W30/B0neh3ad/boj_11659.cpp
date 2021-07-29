/*
    구간 합 구하기 4
    https://www.acmicpc.net/problem/11659
*/
#include <cstdio>
using namespace std;

int pre_sum[100001];

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);

    int temp;
    for(int i=0; i<N; ++i){
        scanf("%d", &temp);
        pre_sum[i+1] = pre_sum[i] + temp;
    }

    int s, e;
    for(int i=0; i<M; ++i){
        scanf("%d %d", &s, &e);
        printf("%d\n", pre_sum[e] - pre_sum[s-1]);
    }
    return 0;
}
/*
    cin, cout이라 당했다;;
    scanf, printf가 ㄹㅇ 빠르긴 하네
*/