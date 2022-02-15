/*
    색종이 붙이기
    https://www.acmicpc.net/problem/17136
*/

#include <iostream>
#include <vector>

using namespace std;

const int INF = 100;
int area[10][10];
int paper_remain[6] = {0, 5, 5, 5, 5, 5};
int min_paper = INF;
int cnt = 0;

void f(pair<int, int> pos, int size) {
    bool changed = false;
    int r, c;
    //printf("f({%d, %d}, %d)\n", pos.first, pos.second, size);
    if(cnt >= min_paper) return;
    if(size && !paper_remain[size]) return;
    if(pos.first+size > 10 || pos.second+size > 10) return;
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            if(!area[pos.first+i][pos.second+j]) return;
        }
    }
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            area[pos.first+i][pos.second+j] = 0;
        }
    }
    cnt++;
    paper_remain[size]--;

    for(int i=0;i<100;i++) {
        if(area[i/10][i%10] == 1) {
            r = i/10;
            c = i%10;
            changed = true;
            break;
        }
    }

    if(!changed) min_paper = min(min_paper, cnt);
    else for(int k=5;k>=1;k--) {
        f({r, c}, k);
    }

    
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            area[pos.first+i][pos.second+j] = 1;
        }
    }
    cnt--;
    paper_remain[size]++;

}

int main() {
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            scanf("%d", &area[i][j]);
        }
    }
    f({0, 0}, 0);
    printf("%d", (min_paper==100)?-1:min_paper-1);
}