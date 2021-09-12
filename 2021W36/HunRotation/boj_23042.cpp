/*
    AND와 OR
    https://www.acmicpc.net/problem/23042
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int A[300000];
int bits[30];
int temp = 0;
long long ans = 1;
long long test = 0;

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        temp = 0;
        scanf("%d", A+i);
        while(A[i]) {
            bits[temp++] += A[i]%2;
            A[i] /= 2;
        }
    }
   
    for(int i=0;i<N;i++) {
        test = 0;
        for(int j=0;j<30;j++) {
            if(bits[j] > 0) {
                test = test | (1 << j);
                bits[j] -= 1;
            }
        }
        ans = (test % 1000000007) * ans % 1000000007;
    }
    printf("%lld", ans);
}