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
    queue<vector<int>> q;
    vector<int> request;
    int added_cost;

    min_costs[0][0] = 0;
    if (board[1][0] == 0) {
        vector<int> temparr = {1, 0, 100, 1};
        q.push(temparr);
    }
    if (board[0][1] == 0) {
        vector<int> temparr = {0, 1, 100, 2};
        q.push(temparr);
    }
    while (!q.empty()) {
        request = q.front();
        //printf("[%d, %d ,%d ,%d]\n", request[0], request[1], request[2], request[3]);
        q.pop();
        if(min_costs[request[0]][request[1]] >= request[2]) {
            min_costs[request[0]][request[1]] = request[2];
            if(request[0] < board.size()-1 && board[request[0]+1][request[1]] == 0) {
                //printf("to down\n");
                vector<int> t = {request[0]+1, request[1], 
                (request[3]==1)?(min_costs[request[0]][request[1]]+100)
                :(min_costs[request[0]][request[1]]+600), 1};
                //printf("<%d %d %d %d>\n", t[0], t[1], t[2], t[3]);
                q.push(t);
            }
            if(request[0] > 0 && board[request[0]-1][request[1]] == 0) {
                //printf("to up\n");
                vector<int> t = {request[0]-1, request[1], 
                (request[3]==-1)?(min_costs[request[0]][request[1]]+100)
                :(min_costs[request[0]][request[1]]+600), -1};
                //printf("<%d %d %d %d>\n", t[0], t[1], t[2], t[3]);
                q.push(t);
            }
            if(request[1] < board.size()-1 && board[request[0]][request[1]+1] == 0) {
                //printf("to right %d %d\n", request[0], request[1]+1);
                vector<int> t = {request[0], request[1]+1, 
                (request[3]==2)?(min_costs[request[0]][request[1]]+100)
                :(min_costs[request[0]][request[1]]+600), 2};
                //printf("<%d %d %d %d>\n", t[0], t[1], t[2], t[3]);
                q.push(t);
            }
            if(request[1] > 0 && board[request[0]][request[1]-1] == 0) {
                //printf("to left %d %d\n", request[0], request[1]+1);
                vector<int> t = {request[0], request[1]-1, 
                (request[3]==-2)?(min_costs[request[0]][request[1]]+100)
                :(min_costs[request[0]][request[1]]+600), -2};
                //printf("<%d %d %d %d>\n", t[0], t[1], t[2], t[3]);
                q.push(t);
            }
        }
    }

    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board.size();j++) {
            printf("%7d ", min_costs[i][j]);
        }
        printf("\n");
    }
    answer = min_costs[board.size()-1][board.size()-1];
    return answer;
}

int main() {
    int a[8][8] = {{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0}};
    vector<vector<int>> v(8);
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            v[i].push_back(a[i][j]);
        }
    }
    solution(v);
}
// keyword: BFS
// 시간복잡도: O(N^2))
/*
idea: 더 작거나 같은 cost의 길이 나올 때마다 새로 queue에 작업을 넣음
*/ 