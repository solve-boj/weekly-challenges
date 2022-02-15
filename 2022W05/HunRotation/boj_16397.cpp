/*
    벽 부수고 이동하기
    https://www.acmicpc.net/problem/2206
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1000000;
int N, T, G;
queue<pair<int, int>> q;
pair<int, int> cur;
int m[100000];

int main() {
    for(int i=0;i<100000;i++) {
        m[i] = INF;
    }
    int temp, exp;
    scanf("%d%d%d", &N, &T, &G);
    q.push({N, 0});
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        m[cur.first] = cur.second;
        if(cur.first == G) break;
        if(cur.second < T) {
            if(cur.first < 99999 && m[cur.first+1] > cur.second+1) q.push({cur.first+1, cur.second+1});
            if(cur.first < 50000 && cur.first > 0) {
                temp = cur.first * 2;
                exp = 1;
                while(temp >= 10) {
                    temp /= 10;
                    exp *= 10;
                }
                if(m[cur.first*2-exp] > cur.second+1) q.push({cur.first*2-exp, cur.second+1});
            }
        }
    }
    if(m[G] == INF) printf("ANG");
    else printf("%d", m[G]);
}