/*
    추석 트래픽
    https://programmers.co.kr/learn/courses/30/lessons/17676
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int, int>> points;
    for(string line: lines){
        int hour, min;
        int end_time;
        float second;
        float duration;
        sscanf(line.c_str(), "2016-09-15 %d:%d:%f %fs", &hour, &min, &second, &duration);
        end_time = 3600000*hour + 60000*min + 1000*second;
        int start_time = end_time-duration*1000+1;
        points.push_back({start_time, +1});
        points.push_back({end_time+1000, -1});
    }
    sort(points.begin(), points.end());
    int handling = 0;
    for(auto point: points){
        handling += point.second;
        answer = max(answer, handling);
    }
    return answer;
}