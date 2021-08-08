
/*
    크레인 인형뽑기 게임
    https://programmers.co.kr/learn/courses/30/lessons/64061
*/
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> basket;
    basket.push_back(0);
    for(int col: moves){
        col--;
        for(int row=0;row<board.size();row++){
            int character = board[row][col];
            if(character){
                board[row][col] = 0;
                if(basket.back() == character){
                    basket.pop_back();
                    answer+=2;
                } else {
                    basket.push_back(character);
                }
                break;
            }
        }
    }
    return answer;
}