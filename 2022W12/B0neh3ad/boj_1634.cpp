#include <bits/stdc++.h>
using namespace std;

int k;
int lhs[2048], rhs[2048];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;

    int n = pow(2, k);
    for(int i=0; i<n; ++i){
        cin >> lhs[i];
    }
    for(int i=0; i<n; ++i){
        cin >> rhs[i];
    }
    

    return 0;
}