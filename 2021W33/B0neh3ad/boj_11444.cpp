/*
    피보나치 수 6
    https://www.acmicpc.net/problem/11444
*/
#include <iostream>

using namespace std;

const int MOD = 1000000;

unsigned long long mat[2][2] = {{1, 1}, {1, 0}};
unsigned long long res[2][2], temp[2][2];

void square(unsigned long long num){
    if(num == 0){ return; }
    if(num == 1){
        for(int i=0; i<2; ++i){
            for(int j=0; j<2; ++j)
                res[i][j] = mat[i][j];
        }
        return;
    }

    square(num/2);

    unsigned long long t;
    for(int i=0; i<2; ++i){
        for(int j=0; j<2; ++j){
            t = 0;
            for(int k=0; k<2; ++k)
                t += res[i][k] * res[k][j];
            temp[i][j] = t%MOD;
        }
    }

    if(num%2){ // 홀수
        for(int i=0; i<2; ++i){
            for(int j=0; j<2; ++j){
                t = 0;
                for(int k=0; k<2; ++k)
                    t += temp[i][k] * mat[k][j];
                res[i][j] = t%MOD;
            }
        }
    }
    else{ // 짝수
        for(int i=0; i<2; ++i){
            for(int j=0; j<2; ++j){
                res[i][j] = temp[i][j];
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unsigned long long n;

    cin >> n;
    square(n);
    cout << res[1][0];

    return 0;
}
/*
    피보나치는 행렬의 제곱으로 간편하게(?) 구할 수 있다.
    시간복잡도는 O(logn)
*/