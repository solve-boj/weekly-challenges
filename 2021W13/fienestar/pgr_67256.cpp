/*
    키패드 누르기
    https://programmers.co.kr/learn/courses/30/lessons/67256
*/
#include <bits/stdc++.h>

using namespace std;

string solution(vector<int> numbers, string hand)
{
    using pos = pair<size_t, size_t>;
    list<char> answer;
    pos right_hand = {3,2};
    pos left_hand = {3,0};
    pos number_pos[] = {{3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
    
    auto get_distance = [](pos a, pos b) {
        return abs(int(a.first) - int(b.first)) + abs(int(a.second) - int(b.second));
    };
    
    auto mark_left = [&](size_t number) {
        left_hand = number_pos[number];
        answer.push_back('L');
    };
    
    auto mark_right = [&](size_t number) {
        right_hand = number_pos[number];
        answer.push_back('R');
    };
    
    for(auto number:numbers)
    {
        if(number % 3 == 1)
            mark_left(number);
        else if(number != 0 and number % 3 == 0)
            mark_right(number);
        else{
            size_t right_distance = get_distance(right_hand, number_pos[number]);
            size_t left_distance = get_distance(left_hand, number_pos[number]);
            
            if(right_distance == left_distance){
                if(hand == "right")
                    mark_right(number);
                else
                    mark_left(number);
            }else if(right_distance < left_distance)
                mark_right(number);
            else
                mark_left(number);
        }
    }
    
    return {answer.begin(),answer.end()};
}