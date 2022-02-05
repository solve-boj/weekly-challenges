#include <bits/stdc++.h>
int cache[21][21][21];

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0){ return 1; }
    if(a > 20 || b > 20 || c > 20){ return w(20, 20, 20); }
    if(cache[a][b][c] != 0){ return cache[a][b][c]; }

    int res;
    if(a < b && b < c){
        res = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }
    else {
        res = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }  
    cache[a][b][c] = res;
    return res;
}

int main(void){
    int a, b, c;
    while(true){
        scanf("%d %d %d", &a, &b, &c);
        if(a == -1 && b == -1 && c == -1){ break; }
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
    return 0;
}