#include <bits/stdc++.h>
char str1[1001], str2[1001];
int n;

int find_next_c(int idx, char obj){
    for(int i=idx; i<n; ++i){
        if(obj == str2[i]){
            return i;
        }
    }
    return -1;
}

int main(void){
    scanf("%s %s", str1, str2);
    n = strlen(str1);

    return 0;
}