/*
    카드2
    https://www.acmicpc.net/problem/2164
*/
#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;

    if(N <= 2){ cout << N; }
    else{
        int sq_2 = 1;
        while(N > sq_2) { sq_2 *= 2; }
        if(N == sq_2){ cout << N; }
        else{
            sq_2 /= 2;
            cout << int((N - sq_2) % sq_2) * 2;
        }
    }
    return 0;
}