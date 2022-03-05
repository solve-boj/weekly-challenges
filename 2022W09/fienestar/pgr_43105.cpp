/*
    정수 삼각형
    https://programmers.co.kr/learn/courses/30/lessons/43105
*/

#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> triangle) {
    
    for(size_t i=1; i!=triangle.size(); ++i){
        triangle[i][0] += triangle[i-1][0];
        for(size_t j=1; j+1!=triangle[i].size(); ++j)
            triangle[i][j] += max(triangle[i-1][j-1],triangle[i-1][j]);
        triangle[i][triangle[i].size()-1] += triangle[i-1][triangle[i].size()-2];
    }
    
    auto& last = triangle[triangle.size()-1];
    
    return *max_element(last.begin(), last.end());
}