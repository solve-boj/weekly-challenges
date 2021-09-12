/*
    암호 만들기
    https://www.acmicpc.net/problem/1759
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int L, C;
char A[15], P[16];
bool isVowel[26];

void bt(int len, int prev, int ccount, int vcount) {
    if (len == L) {
        if(ccount >= 2 && vcount >= 1) printf("%s\n", P);
        return;
    }
    for(int i=prev+1;i<C;i++) {
        P[len] = A[i];
        bt(len+1, i, ccount+!isVowel[A[i]-'a'], vcount+isVowel[A[i]-'a']);
    }

}

int main() {
    scanf("%d %d", &L, &C);
    for(int i=0;i<C;i++) {
        scanf(" %c", A+i);
    }
    sort(A, A+C);
    isVowel[0] = isVowel[4] = isVowel[8] = isVowel[14] = isVowel[20] = true;
    bt(0, -1, 0, 0);
}


// keyword: 백트래킹
// 시간복잡도: O(C^L)
/*
idea: 길이가 L이면 printf
len 길이까지 각각에 대해 재귀
*/