/*
    행렬 제곱
    https://www.acmicpc.net/problem/10830
*/
#include <iostream>
#include <stack>

using namespace std;

int n;
long long b;
long long matrix[5][5], temp[5][5]; // 원본, temp
long long res[5][5]; // 결과

void square(long long num){
    if(num <= 1){ // base case
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                res[i][j] = matrix[i][j] % 1000;
            }
        }
        return;
    }
    square(num/2);

    long long t;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            t = 0;
            for(int k=0; k<n; ++k){
                t += res[i][k] * res[k][j];
            }
            temp[i][j] = t % 1000;
        }
    }

    if(num % 2){ // 홀수 제곱
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                t = 0;
                for(int k=0; k<n; ++k){
                    t += temp[i][k] * matrix[k][j];
                }
                res[i][j] = t % 1000;
            }
        }
    }
    else{ // 짝수 제곱
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                res[i][j] = temp[i][j];
            }
        }
    }
}

int main(void){
    cin >> n >> b;

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> matrix[i][j];
            res[i][j] = 1;
        }
    }

    square(b);
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
/*
    입력값 범위는 1000 이하인데
    1000으로 나눈 나머지를 출력하라고 했으니
    base case에서도 1000으로 나누어주어야 한다.
*/