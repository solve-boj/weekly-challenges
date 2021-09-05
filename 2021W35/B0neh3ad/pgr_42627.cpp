#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int solution(vector<vector<int>> jobs) {
    vector<pii> sorted_jobs;
    // <요청 시각, 작업 시간>
    priority_queue<pii, vector<pii>, greater<pii> > sch;
    for(auto& job: jobs)
        sorted_jobs.push_back(pii(job[0], job[1]));
    sort(sorted_jobs.begin(), sorted_jobs.end());
    // <작업 시간, 요청 시각>
    sch.push(pii(sorted_jobs[0].second, sorted_jobs[0].first));
    int curr = 0, answer = 0;
    int next_idx = 1;
    for(int i=0; i<jobs.size(); ++i){
        if(curr < sch.top().second)
            curr = sch.top().second;
        answer += (curr - sch.top().second) + sch.top().first;
        curr += sch.top().first;
        sch.pop();

        if(next_idx < jobs.size()){
            while(sorted_jobs[next_idx].first <= curr){
                sch.push(pii(sorted_jobs[next_idx].second, sorted_jobs[next_idx].first));
                ++next_idx;
                if(next_idx >= jobs.size())
                    break;
            }
            if(next_idx < jobs.size() && sch.empty())
                sch.push(pii(sorted_jobs[next_idx++].second, sorted_jobs[next_idx++].first));
        }
    }
    answer /= jobs.size();
    return answer;
}

/*
    뻘짓을 많이 해서 좀 오래 걸렸다
*/