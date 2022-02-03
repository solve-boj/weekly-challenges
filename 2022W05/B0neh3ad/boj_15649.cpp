#include <bits/stdc++.h>
using namespace std;

int n, m;
bool check[9];

void sol(string seq, int len){
    if(len == m){
        printf("%s\n", seq.c_str());
        return;
    }

    for(int i=1; i<=n; ++i){
        if(!check[i]){
            check[i] = true;
            sol(seq + to_string(i) + " ", len+1);
            check[i] = false;
        }
    }
}

int main(void){
    scanf("%d %d", &n, &m);

    sol("", 0);
    return 0;
}