/*
    And the Winner Is... Ourselves!
    https://www.acmicpc.net/problem/17509
    실버4 이하
*/

#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> problems[11];
int totaltime[11];

int main() {
    int d, v, sum=0;
    for (int i=0;i<11;i++) {
        scanf("%d %d", &d, &v);
        problems[i] = make_pair(d, v);
    }
    sort(problems, problems + 11);
    for (int i=0;i<11;i++) {
        totaltime[i] = (i==0)?problems[i].first:(totaltime[i-1]+problems[i].first);
        sum += totaltime[i] + 20 * problems[i].second;
    }
    printf("%d", sum);
}

// keyword: 그리디 알고리즘
// 시간복잡도: O(N log N)
/*
idea: 시간이 적게 드는 문제부터 solve
*/