#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    answer.reserve(queries.size());
    
    vector<vector<int>> board(rows, vector<int>(columns));
    {
        size_t k = 1;
        for(auto& line:board)
            for(auto& x:line)
                x = k++;
    }
    
    auto rotate = [&](size_t x1, size_t y1, size_t x2, size_t y2) {
        static int dx[] = {0,1,0,-1};
        static int dy[] = {1,0,-1,0};

        auto x = x1;
        auto y = y1;

        int last = board[x][y];
        int m = board[x][y];
        for(size_t k=0; k!=4; ++k)
            while(x + dx[k] - x1 < x2 - x1 && y + dy[k] - y1 < y2 - y1){
                x = x + dx[k];
                y = y + dy[k];
                
                m = min(m, board[x][y]);
                
                swap(last, board[x][y]);
            }
        answer.push_back(m);
    };
    
    for(auto& query:queries)
        rotate(query[0]-1, query[1]-1, query[2], query[3]);
    
    return answer;
}