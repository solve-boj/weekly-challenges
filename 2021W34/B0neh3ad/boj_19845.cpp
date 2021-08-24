/*
    넴모넴모 2020
    https://www.acmicpc.net/problem/19845
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){
    int N, Q;
    scanf("%d %d", &N, &Q);
    long long grid[N];
    for(int i=N-1; i>=0; --i){
        scanf("%lld", &grid[i]);
    }
    for(int i=0; i<Q; ++i){
        int x, y;
        scanf("%d %d", &x, &y);
        y = N - y;
        long long answer = (y+1) - (lower_bound(grid, grid+N, x) - grid) + (grid[y] - x);
        if(answer < 0){ answer = 0; }
        printf("%lld\n", answer);
    }
    return 0;
}
/*
    O(N)으로 푸려면 x좌표에 대응되는 넴모의 수를 일일히 저장해야 하므로
    공간복잡도가 매우 커진다.
    따라서 이분 탐색을 이용해 O(NlogN)에 풀 수 있다.
*/