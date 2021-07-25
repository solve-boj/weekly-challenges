/*
    피보나치 함수
    https://www.acmicpc.net/problem/1003
*/
#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    int N;
    for(int i=0; i<T; ++i){
        cin >> N;
        int a = 1, b = 0, c;
        for(int j=0; j<N; ++j){
            c = a + b;
            a = b;
            b = c;
        }
        cout << a << " " << b << '\n';
    }
    return 0;
}