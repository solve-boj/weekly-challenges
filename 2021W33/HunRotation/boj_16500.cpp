/*
    문자열 판별
    https://www.acmicpc.net/problem/16500
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
char S[101];
int N;
char A[100][101];
int table[100];

int f(int start) {
    //printf("%d\n", start);
    if(start == strlen(S)) return 1;
    if(table[start] != -1) {
        return table[start];
    }
    int res = 0;
    for(int i=0;i<N;i++) {
        bool flag = true;
        if(strlen(A[i]) > strlen(S) - start) continue;
        for(int j=0;j<strlen(A[i]);j++) {
            if(A[i][j] != S[start+j]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            res = res || f(start+strlen(A[i]));
        }
    }
    return table[start] = res;
}

int main() {

    scanf("%s\n", S);
    scanf("%d", &N);
    for(int i=0;i<strlen(S);i++) {
        table[i] = -1;
    }
    for(int i=0;i<N;i++) {
        if (i != N-1) scanf("%s\n", A[i]);
        else scanf("%s", A[i]);
    }
    printf("%d", f(0));
}


// keyword: DP
// 시간복잡도: O(N^2 L) (L은 A 내 문자열의 최대 길이)
/*
idea: start부터 시작하는 S의 부분 문자열을 주어진 A의 문자열로 완성할 수 있는가가 f(start)
각 문자열이 맨 앞에 매칭되는지 확인하고 매칭되면 재귀
*/