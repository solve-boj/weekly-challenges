/*
    추석 트래픽
    https://programmers.co.kr/learn/courses/30/lessons/17676
*/

#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

priority_queue<pair<int, int>> pq;

int solution(vector<string> lines) {
    int answer = 0;
    int cur = 0;
    int h, m;
    int s, ms, temp;
    double time_ms;
    vector<pair<int, int>> tasktime;
    for(int i=0;i<lines.size();i++) {
        sscanf(lines[i].c_str(), "2016-09-15 %d:%d:%d.%d %lfs", &h, &m, &s, &ms, &time_ms);
        temp = 3600000*h + 60000*m + 1000*s + ms;
        tasktime.push_back(make_pair(temp - (int)(time_ms*1000 + 0.1) + 1, temp));
    }
    for(int i=0;i<tasktime.size();i++) {
        pq.push(make_pair(-tasktime[i].first, -1));
        pq.push(make_pair(-(tasktime[i].second + 1000), 1));
    }

    int curtime, dcur;
    while(!pq.empty()) {
        curtime = -pq.top().first;
        dcur = -pq.top().second;
        //printf("%d %d %d\n", curtime, dcur, pq.size());
        cur += dcur;
        pq.pop();
        while(!pq.empty() && curtime == -pq.top().first) {
            cur += -pq.top().second;
            //printf("%d %d %d\n", curtime, -pq.top().second, pq.size());
            pq.pop();
        }
        answer = max(answer, cur);
    }


    return answer;
}


int main() {
    vector<string> v = {"2016-09-15 01:00:04.002 2.0s",
    "2016-09-15 01:00:07.000 2s"};
    int a = solution(v);
    printf("%d", a);
}

// keyword: 스택, 문자열 포맷
// 시간복잡도: O(N)
/*
idea: 각 처리가 시작되는 시점, 끝나는 시점을 ms로 표기, 
처리 시작과 끝을 -1, +1로 구분해 priority_queue에 pair로 넣음
시간 순서대로 처리 시작, 끝을 처리
*/