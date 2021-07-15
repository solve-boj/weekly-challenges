/*
    N으로 표현
    https://programmers.co.kr/learn/courses/30/lessons/42895
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int front_idx = 0;
    while(front_idx < progresses.size()){
        int cnt = 0;
        for(int i=front_idx; i<progresses.size(); i++){ progresses[i] += speeds[i]; }
        for(int i=front_idx; (i<progresses.size()) && (progresses[i] >= 100); i++, cnt++){}
        if(cnt > 0){
            answer.push_back(cnt);
            front_idx += cnt;
        }
    }
    return answer;
}