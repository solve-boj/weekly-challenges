/*
    크레인 인형뽑기 게임
    https://programmers.co.kr/learn/courses/30/lessons/64061
*/

#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    const auto n = board.size();
    const auto m = board[0].size();
    vector<size_t> l(m);
    for(size_t i=0; i!=l.size(); ++i){
        size_t j=0;
        while(!board[j][i] && j != n)++j;
        l[i] = j;
    }
    
    size_t boom = 0;
    stack<int> s;
    for(auto move:moves){
        --move;
        
        if(l[move] == n)continue;
        
        if(s.size() && s.top() == board[l[move]][move]){
            ++boom;
            s.pop();
        }else
            s.push(board[l[move]][move]);

        l[move]++;
    }
    
    return boom * 2;
}