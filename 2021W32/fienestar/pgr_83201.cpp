/*
    상호 평가
    https://programmers.co.kr/learn/courses/30/lessons/83201
*/
#include <bits/stdc++.h>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    for(size_t i=0; i!=scores.size(); ++i) {
        int& me = scores[i][i];
        
        int sum = accumulate(scores.begin(), scores.end(), 0, [&](int sum, auto& score){
            return sum + score[i];
        });
        
        bool is_biggest = all_of(scores.begin(), scores.end(), [&](auto& score){
            return me > score[i] || &me == &score[i];
        });
        
        bool is_least = all_of(scores.begin(), scores.end(), [&](auto& score){
            return me < score[i] || &me == &score[i];
        });
        
        int avg = sum / scores.size();
        
        if(is_biggest || is_least)
            avg = (sum - me) / (scores.size()-1);
        
        answer += "FFFFFDDCBAA"[avg / 10];
    }
    
    return answer;
}