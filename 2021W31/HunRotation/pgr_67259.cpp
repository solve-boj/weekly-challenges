/*
    경주로 건설
    https://programmers.co.kr/learn/courses/30/lessons/67259
*/

#include <cstdio>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> board) {
    const int INF = 1000000;
    vector<vector<int>> min_costs(board.size());
    for (int i=0;i<board.size();i++) {
        for(int j=0;j<board.size();j++) {
            min_costs[i].push_back(INF);
        }
    }
    
    int answer = 0;
    queue<int*> q;
    int * request;
    int added_cost;

    min_costs[0][0] = 0;
    if (board[1][0] == 0) {
        int temparr[4] = {1, 0, 100, 1};
        q.push(temparr);
    }
    if (board[0][1] == 0) {
        int temparr[4] = {0, 1, 100, 2};
        q.push(temparr);
    }
    while (!q.empty()) {
        request = q.front();
        q.pop();
        if(min_costs[request[0]][request[1]] > request[2]) {
            min_costs[request[0]][request[1]] = request[2];
            if(request[0] > 0 && board[request[0]-1][request[1]] == 0) {
                int temparr[4] = {request[0]-1, request[1], 
                (request[3]==-1)?(min_costs[request[0]][request[1]]+100)
                :(min_costs[request[0]][request[1]]+500), -1};
                q.push(temparr);
            }
            if(request[0] < board.size()-1 && board[request[0]+1][request[1]] == 0) {
                int temparr[4] = {request[0]+1, request[1], 
                (request[3]==1)?(min_costs[request[0]][request[1]]+100)
                :(min_costs[request[0]][request[1]]+500), 1};
                q.push(temparr);
            }
            if(request[1] > 0 && board[request[0]][request[1]-1] == 0) {
                int temparr[4] = {request[0], request[1]-1, 
                (request[3]==-2)?(min_costs[request[0]][request[1]]+100)
                :(min_costs[request[0]][request[1]]+500), -2};
                q.push(temparr);
            }
            if(request[1] < board.size()-1 && board[request[0]][request[1]+1] == 0) {
                int temparr[4] = {request[0], request[1]+1, 
                (request[3]==2)?(min_costs[request[0]][request[1]]+100)
                :(min_costs[request[0]][request[1]]+500), 2};
                q.push(temparr);
            }
        }
    }


    answer = min_costs[board.size()-1][board.size()-1];
    return answer;
}

int main() {
    int a[3][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    
}
// keyword: BFS
// 시간복잡도: O(N^2))
/*
idea: string을 순서대로 정렬하면, 앞쪽 파트가 똑같을 때 길이가 더 긴 것이
더 짧은 것 바로 뒤에 온다는 점을 이용
*/ 