/*
    제곱수의 합
    https://www.acmicpc.net/problem/1699
*/

#include <bits/stdc++.h>

using namespace std;


void check(size_t dim,size_t sum)
{
    if(!dim)return;
    for(size_t i=1;i<=sum/i;++i){
        if(i*i==sum){
            cout << 4-dim;
            exit(0);
        }
        check(dim-1,sum-i*i);
    }
}

int main()
{
    size_t N;
    cin >> N;
    check(3,N);
    cout << 4;
    return 0;
}