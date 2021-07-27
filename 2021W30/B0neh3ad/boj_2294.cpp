/*
    동전 2
    https://www.acmicpc.net/problem/2294
*/
#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int value[n];
    int check[k+1] = {0, };
    for(int val: value){
        cin >> val;
        for(int i=0; i<=k-val; ++i){
            if(check[i] || !i)
                check[i+val] = check[i+val] ? min(check[i]+1, check[i+val]) : check[i]+1;
        }
    }

    cout << (check[k] ? check[k] : -1);
    return 0;
}