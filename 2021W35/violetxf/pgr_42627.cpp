/*
    디스크 컨트롤러
    https://programmers.co.kr/learn/courses/30/lessons/42627
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    int availableOn = 0;
    int i = 0;
    while(i<jobs.size() || !pq.empty()){
        while(i<jobs.size() && jobs[i][0] <= availableOn){
            pq.push(jobs[i++]);
        }
        if(!pq.empty()){
            availableOn+=pq.top()[1];
            answer += availableOn - pq.top()[0];
            pq.pop();
        } else {
            availableOn = jobs[i][0];
        }
    } 
    return answer/jobs.size();
}