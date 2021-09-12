/*
    실 전화기
    https://www.acmicpc.net/problem/23039
*/

#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

set<pair<int, int>> lines;
vector<int> points;
pair<int, int> cases[2] = {{0,2},{1,3}};
int N, ans = 0, cnt = 0;
set<set<int>> inter;
bool flag = false, sflag = true;
int c[6];

void bt(int num) {
    if(points.size() == 4) {
        cnt = 0;
        for(int i=0;i<2;i++) {
            if(lines.find({points[cases[i].first], points[cases[i].second]}) !=
            lines.end()) cnt++;
        }
        //printf("%d %d %d %d: %d\n", points[0], points[1], points[2], points[3], cnt);
        if (cnt == 2) {
            inter.insert({points[0], points[1], points[2], points[3]});
        };
    }
    if(num == 5) return;
    bt(num+1);
    points.push_back(num+1);
    bt(num+1);
    points.pop_back();
}

int main() {
    int a, b;
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d %d", &a, &b);
        lines.insert({a<b?a:b, a<b?b:a});
        c[a]++;
        c[b]++;
    } 
    if (lines.size() == 10) {
        printf("-1");
        return 0;
    }
    
    bt(0);

    if(inter.empty()) {
        printf("0");
        return 0;
    }
    for(int i=1;i<=5;i++) {
        sflag = true;
        for(auto it=inter.begin();it!=inter.end();it++) {
            if((*it).find(i) == (*it).end()) sflag = false;
        }
        if(sflag) {
            flag = true;
            break;
        }
    }

    printf("%d", flag?1:2);
}