/*
    색종이 만들기
    https://www.acmicpc.net/problem/2630
*/
#include <iostream>

using namespace std;

int n;
int paper[128][128];
int res[2]; // 0: 흰색, 1: 파란색

// (y, x): 시작점 좌표
// num: 가로 세로 길이
void checkPapers(int y, int x, int num){
    if(num == 1){ // base case
        ++res[paper[y][x]];
        return;
    }

    // checking
    int init = paper[y][x];
    bool flag = true;
    for(int i=y; (i<y+num && flag); ++i){
        for(int j=x; (j<x+num && flag); ++j){
            if(paper[i][j] != init)
                flag = false;
        }
    }

    if(flag){
        ++res[init];
    }
    else{
        checkPapers(y, x, num/2);
        checkPapers(y, x+num/2, num/2);
        checkPapers(y+num/2, x, num/2);
        checkPapers(y+num/2, x+num/2, num/2);
    }
}

int main(void){
    cin >> n;

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> paper[i][j];
        }
    }

    checkPapers(0, 0, n);
    cout << res[0] << '\n' << res[1];
    return 0;
}
/*
    전형적인 분할정복 문제
*/