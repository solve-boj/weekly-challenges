/*
    입실 퇴실
    https://programmers.co.kr/learn/courses/30/lessons/86048
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
    int n = enter.size(), in_cnt = 0;
    vector<int> answer(n, 0);
    vector<bool> is_in(n+1, false);
    
    for(size_t i=0; i<n; ++i){
        is_in[enter[i]] = true;
        if(++in_cnt >= 2){
            for(size_t j=1; j<=n; ++j){
                if(is_in[j]){
                    if(j == enter[i]){ answer[j-1] += in_cnt-1; }
                    else{ ++answer[j-1]; }
                }
            }
        }
        while(is_in[leave[i+1-in_cnt]]){
            is_in[leave[i+1-in_cnt]] = false;
            if(--in_cnt < 1) break;
        }
    }
    return answer;
}