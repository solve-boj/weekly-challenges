/*
    크레인 인형뽑기 게임
    https://programmers.co.kr/learn/courses/30/lessons/64061
*/

#include <cstdio>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    const int N = board.size();
    int answer = 0;
    stack<int>* lanes = new stack<int>[N];
    stack<int> basket;

    for(int i=N-1;i>=0;i--) {
        for (int j=0;j<N;j++) {
            if(board[i][j] != 0) {
                lanes[j].push(board[i][j]);
            }
        }
    }

    for(int i=0;i<moves.size();i++) {
        if (lanes[moves[i]-1].empty()){
            continue;
        }
        else if(!basket.empty() && basket.top() == lanes[moves[i]-1].top()) {
            lanes[moves[i]-1].pop();
            basket.pop();
            answer += 2;
        }
        else {
            basket.push(lanes[moves[i]-1].top());
            lanes[moves[i]-1].pop();
        }
    }

    delete [] lanes;
    return answer;
    
}

// keyword: 스택
// 시간복잡도: O(moves 크기)
/*
idea: 격자 화면의 각 열을 stack으로 구현, 바구니도 stack으로 구현
*/