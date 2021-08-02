/*
    크레인 인형뽑기 게임
    https://programmers.co.kr/learn/courses/30/lessons/64061
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0; // 사라진 인형
    vector<int> basket; // 바구니
    vector<int> board_cnt(board.size(), 0); // 각 column 별 인형 개수

    // board_cnt 초기화
    for(int i=board.size(); i>0; --i){
        for(int j=0; j<board.size(); ++j){
            if(!board_cnt[j] && board[board.size()-i][j]){
                board_cnt[j] = i;
            }
        }
    }

    for(auto move: moves){
        if(board_cnt[move-1]){ // 해당 column에 인형이 있다면
            basket.push_back(board[board.size()-board_cnt[move-1]][move-1]); // 인형 넣고
            --board_cnt[move-1];
            while(basket.size() > 1){
                if(basket[basket.size()-1] == basket[basket.size()-2]){ // 맨 마지막 두 인형이 같다면
                    // 인형 두 개 빼고
                    basket.pop_back();
                    basket.pop_back();
                    // 개수 세기
                    answer += 2;
                }
                else{ break; }
            }
        }
    }
    return answer;
}
/*
    단순 구현 문제
    stack으로 구현하고, top() 이용해서 중복 체크한 뒤
    인형이 중복되지 않는 경우에만 삽입하는 게 이상적일 듯.
*/