/*
    종이의 개수
    https://www.acmicpc.net/problem/1780
*/

#include <cstdio>
#include <vector>

using namespace std;

int paper[2187][2187];

int N;

vector<int> f(int xstart, int xend, int ystart, int yend) {
    vector<int> sheets(3);
    if(xstart + 1 == xend) {
        sheets[paper[xstart][ystart] + 1]++;
        return sheets;
    }
    int count[3] = {};
    for(int i=xstart;i<xend;i++) {
        for(int j=ystart;j<yend;j++) {
            count[paper[i][j]+1]++;
        }
    }
    for(int i=0;i<3;i++) {
        sheets[i] += count[i] / ((xend-xstart)*(yend-ystart));
    }
    if(count[0]!=(xend-xstart)*(yend-ystart) && count[1]!=(xend-xstart)*(yend-ystart)
    && count[2]!=(xend-xstart)*(yend-ystart)) {
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                vector<int> another_sheets = f(xstart+(xend-xstart)/3*i, xstart+(xend-xstart)/3*(i+1),
                ystart + (yend-ystart)/3*j, ystart+(yend-ystart)/3*(j+1)); 
                for(int k=0;k<3;k++) {
                    sheets[k] += another_sheets[k];
                }
            }
        }
    }
    return sheets;
}

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            scanf("%d", &paper[i][j]);
        }
    }
    vector<int> sheets = f(0, N, 0, N);
    printf("%d\n", sheets[0]);
    printf("%d\n", sheets[1]);
    printf("%d\n", sheets[2]);
}

// keyword: 분할 정복
// 시간복잡도: O(N log N)
/*
idea: 정사각형 내 모든 숫자가 같으면 그대로 해당 개수에 1 더함
그렇지 않으면 3*3으로 영역을 나누어 함수를 재귀 호출, 얻은 값을 각각 모두 더함
*/