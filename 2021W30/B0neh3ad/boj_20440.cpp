/*
    🎵니가 싫어 싫어 너무 싫어 싫어 오지 마 내게 찝쩍대지마🎵 - 1
    https://www.acmicpc.net/problem/20440
*/
#include <cstdio>
#include <algorithm>

int N;
int S[1000001], E[1000001];
int max_cnt, curr_cnt;
int max_s, max_e, curr_s, curr_e;
int s_pnt, e_pnt;

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        scanf("%d %d", &S[i], &E[i]);
    }

    std::sort(S, S+N);
    std::sort(E, E+N);

    while((s_pnt < N) || (e_pnt < N)){
        if((e_pnt == N) || ((s_pnt < N && e_pnt < N) && (S[s_pnt] < E[e_pnt]))){ // 늘어나는 경우
            ++curr_cnt;
            curr_s = curr_e = S[s_pnt];
            if(curr_cnt > max_cnt){ // 현재 구간이 max인 경우
                max_cnt = curr_cnt;
                max_s = max_e = S[s_pnt];
            }
            ++s_pnt;
        }
        else if((s_pnt == N) || ((s_pnt < N && e_pnt < N) && (S[s_pnt] > E[e_pnt]))){ // 줄어드는 경우
            if(curr_cnt == max_cnt && curr_s == max_s){ // 현재 구간이 max였던 경우
                max_e = E[e_pnt];
            }
            --curr_cnt;
            curr_s = curr_e = E[e_pnt];
            ++e_pnt;
        }
        else{ // 유지되는 경우
            curr_e = E[e_pnt];
            if(curr_cnt == max_cnt && curr_s == max_s){
                max_e = E[e_pnt];
            }
            ++s_pnt;
            ++e_pnt;
        }
    }

    printf("%d\n", max_cnt);
    printf("%d %d", max_s, max_e);
    return 0;
}