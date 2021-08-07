/*
    강의실 배정
    https://www.acmicpc.net/problem/11000
*/

#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

// 우선순위 지정용 cmp struct 만드는 방법, 꼭 익혀놓기
// true를 반환하는 경우 queue에서 오른쪽 변수(n2)를 더 앞에 둠
struct cmp {
    bool operator()(pair<int, int> n1, pair<int, int> n2) {
        if(n1.second > n2.second) return true;
        else if (n1.second == n2.second) {
            if (n1.first > n2.first) return true;
            else return false;
        }
        return false;
    }
};

int N, max_room = 0;
pair<int, int> lectures[200000];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;

int main() {
    int a, b, prev = 0;
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d %d", &a, &b);
        lectures[i] = make_pair(a, b);
    }
    sort(lectures, lectures + N);
    for(int i=0;i<N;i++) {
        prev = lectures[i].first;
        while (!q.empty() && q.top().second <= prev) {
            q.pop();
        }
        q.push(lectures[i]);
        if (q.size() > max_room) {
            max_room = q.size();
        }
    }
    printf("%d", max_room);
}

// keyword: 그리디 알고리즘, 우선순위 큐
// 시간복잡도: O(N) (우선순위 큐 내부 연산 제외)
/*
idea: 시작 시간이 빠른 순서대로 강의를 정렬해서 하나씩 검사
이 때 우선순위 큐에 있는 강의의 수는 현재 진행 중인 강의의 수
*/