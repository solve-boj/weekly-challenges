/*
    모음 사전
    https://programmers.co.kr/learn/courses/30/lessons/42627
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<pair<int, int>> pq;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int curtime = 0;
    vector<int> check(jobs.size());

    for(int i=0;i<jobs.size();i++) {
        for(int j=0;j<jobs.size();j++) {
            if(!check[j] && curtime >= jobs[j][0]) {
                pq.push({-jobs[j][1], j});
            }
        }
        if(pq.empty()) {
            for(int j=0;j<jobs.size();j++) {
                if(!check[j]) {
                    pq.push({-(10000*(jobs[j][0]) + jobs[j][1] + max(0, jobs[j][0]-curtime)), j});
                }
            }
        }

        check[pq.top().second] = 1;

        curtime += jobs[pq.top().second][1] + max(0, jobs[pq.top().second][0]-curtime);
        answer += curtime - jobs[pq.top().second][0];

        printf("%d %d\n", answer, curtime);

        while(!pq.empty()) {
            pq.pop();
        }
    }
    return answer  / jobs.size();
}

int main() {
    vector<vector<int>> v = {
        {24, 10}, {28, 39}, {43, 20}, {37, 5}, {47, 22},
        {20, 47}, {15, 34}, {15, 2}, {35, 43}, {26, 1}};
    solution(v);
}

// keyword: 정렬, 그리디 알고리즘
// 시간복잡도: O(N^2 log N)
/*
idea:
*/