/*
    멀티탭 스케줄링
    https://www.acmicpc.net/problem/1700
*/

#include <cstdio>
#include <queue>
#include <set>

using namespace std;
int N, K, cnt=0;
int name[100];
queue<int> schedule[101];
set<int> multitab;

int main() {
    int tempmax = 0, tempmax_pos = 0;
    scanf("%d %d", &N, &K);
    for(int i=0;i<K;i++) {
        scanf("%d", &name[i]);
        schedule[name[i]].push(i);
    }
    for(int i=1;i<=K;i++) {
        schedule[i].push(K);
    }
    for(int i=0;i<K;i++) {
        /*
        for(set<int>::const_iterator iter=multitab.begin();
            iter!=multitab.end();iter++) {
            printf("%d ", *iter);        
        }
        printf("\n");
        */
        if (multitab.size() < N) {
            multitab.insert(name[i]);
        }
        else if(multitab.find(name[i]) != multitab.end()) {
            schedule[name[i]].pop();
            continue;
        }
        else {
            for(set<int>::const_iterator iter=multitab.begin();
            iter!=multitab.end();iter++) {
                if (tempmax < schedule[*iter].front()) {
                    tempmax = schedule[*iter].front();
                    tempmax_pos = *iter;
                }
            }
            multitab.erase(tempmax_pos);
            cnt++;
            multitab.insert(name[i]);
        }
        schedule[name[i]].pop();
        tempmax = 0;
        tempmax_pos = 0;
    }
    printf("%d", cnt);
}
// keyword: 그리디 알고리즘, set, queue
// 시간복잡도: O(NK)
/*
idea: 다시 사용하는 시기가 가장 늦은, 또는 다시 사용할 일이 없는 플러그를 뽑고
그 자리에 새 플러그를 꽂음
*/