/*
    동전 1
    https://www.acmicpc.net/problem/2293
*/
#include <cstdio>

using namespace std;

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);

    int coin[n];
    for(int i=0; i<n; ++i){
        scanf("%d", &coin[i]);
    }

    int val[k+1] = {0};
    val[0] = 1;
    for(int i=0; i<n; ++i){
        for(int j=0; j<=k-coin[i]; ++j){
            if(val[j]){
                val[j+coin[i]] += val[j];
            }
        }
    }

    printf("%d", val[k]);
    return 0;
}