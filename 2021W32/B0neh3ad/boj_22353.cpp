/*
    헤이카카오
    https://www.acmicpc.net/problem/22353
*/
#include <cstdio>
#include <cmath>

int main(void){
    double a, d, k;
    scanf("%lf %lf %lf", &a, &d, &k);

    double init = d / 100.0, weight = k / 100.0;
    double lose_rate = 1.0, win_rate = init;
    double expect = 0.0;
    double n = 1.0;
    while(win_rate < 1){
        expect += n*a * lose_rate * win_rate;
        lose_rate *= 1-win_rate;
        ++n;
        win_rate = init*pow(1+weight, n-1);
    }

    expect += n*a * lose_rate;

    printf("%lf", expect);
    return 0;
}
/*
    정확도 때문에... c++로 풀리나? -> double로도 충분
    문제 이해를 제대로 해야 풀리는 문제였다..
*/