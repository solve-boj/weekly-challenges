#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using pidv = pair<int, vector<vector<int>>>;

bool cmp_blank(const pidv& lhs, const pidv& rhs){
    return (lhs.first == rhs.first) ? lhs.second > rhs.second : (lhs.first > rhs.first);
}

bool cmp_block(const pair<pidv, int>& lhs, const pair<pidv, int>& rhs){
    return (lhs.first.first == rhs.first.first) ? true : (lhs.first.first > rhs.first.first);
}

bool isInside(int y, int x, int size){
    return (x*(size-1-x) >= 0) && (y*(size-1-y) >= 0);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int board_size = game_board.size();
    int dx[3] = {1, -1, 0}, dy[3] = {0, 0, 1};
    bool visited[board_size][board_size];
    vector<pidv> blanks;
    vector<pair<pidv, int>> blocks;

    // 1. create blanks list
    for(int i=0; i<board_size; ++i)
        fill(visited[i], visited[i]+board_size, false);

    for(int i=0; i<board_size; ++i){
        for(int j=0; j<board_size; ++j){
            if(game_board[i][j] == 0 && !visited[i][j]){ // 방문 안 한 빈칸 존재
                vector<vector<int>> blank(10, vector<int>(10, 0));
                int blank_size = 1;

                queue<pii> q;
                // 10x10 블럭 배열 내에서의 초기 지점은 (0, 4)
                blank[0][4] = 1;
                // 실제 board 내에서의 초기 지점은 (i, j)
                visited[i][j] = true;
                // queue에는 초기 지점에서 이동한 변위를 저장
                q.push(pii(0, 0));

                while(!q.empty()){
                    int curr_y = q.front().first;
                    int curr_x = q.front().second;
                    // cout << "(" << i + curr_y << ", " << j + curr_x << ") ";
                    q.pop();
                    for(int k=0; k<3; ++k){
                        int next_y = curr_y + dy[k];
                        int next_x = curr_x + dx[k];
                        if(isInside(i+next_y, j+next_x, board_size)){ // 경계 내
                            if(game_board[i+next_y][j+next_x] == 0 && !visited[i+next_y][j+next_x]){ // 빈칸 존재
                                blank[next_y][4+next_x] = 1;
                                visited[i+next_y][j+next_x] = true;
                                q.push(pii(next_y, next_x));
                                ++blank_size;
                            }
                        }
                    }
                }
                blanks.push_back({blank_size, blank});
            }
        }
    }

    sort(blanks.begin(), blanks.end(), cmp_blank);

    // 2. create blocks list
    for(int r=0; r<4; ++r){
        for(int i=0; i<board_size; ++i)
            fill(visited[i], visited[i]+board_size, false);

        int block_id;
        if(r == 0){ block_id = 1000; }
        for(int i=0; i<board_size; ++i){
            for(int j=0; j<board_size; ++j){
                if(table[i][j] && !visited[i][j]){ // 방문 안 한 빈칸 존재
                    if(r == 0){ table[i][j] = block_id; } // 첫 방문 시 id 기록
                    vector<vector<int>> block(10, vector<int>(10, 0));
                    int block_size = 1;

                    queue<pii> q;

                    block[0][4] = 1;
                    visited[i][j] = true;
                    q.push(pii(0, 0));

                    while(!q.empty()){
                        int curr_y = q.front().first;
                        int curr_x = q.front().second;
                        // cout << "(" << i + curr_y << ", " << j + curr_x << ") ";
                        if(table[i+curr_y][j+curr_x] != 1){ block_id = table[i+curr_y][j+curr_x]; } // id 이미 기록된 경우
                        q.pop();
                        for(int k=0; k<3; ++k){
                            int next_y = curr_y + dy[k];
                            int next_x = curr_x + dx[k];
                            if(isInside(i+next_y, j+next_x, board_size)){ // 경계 내
                                if(table[i+next_y][j+next_x] && !visited[i+next_y][j+next_x]){ // 빈칸 존재
                                    block[next_y][4+next_x] = 1;
                                    visited[i+next_y][j+next_x] = true;
                                    q.push(pii(next_y, next_x));
                                    ++block_size;
                                }
                            }
                        }
                    }
                    blocks.push_back({{block_size, block}, block_id});
                    if(r==0)
                        ++block_id;
                    
                }
            }
        }
        cout << blocks.size() << endl;
        cout << "\n";
        // table 회전
        int temp_table[board_size][board_size];
        for(int i=0; i<board_size; ++i)
            for(int j=0; j<board_size; ++j)
                temp_table[j][board_size-1-i] = table[i][j];
        for(int i=0; i<board_size; ++i){
            for(int j=0; j<board_size; ++j){
                table[i][j] = temp_table[i][j];
                cout << table[i][j] << " ";
            }
            cout << "\n";
        }
    }
    sort(blocks.begin(), blocks.end(), cmp_block);

    // 3. find answer
    int answer = 0;
    vector<int> blank_flag(blanks.size(), 0);
    vector<int> used_block_flag(blocks.size(), 0);
    cout << blanks.size() << " " << blocks.size() << endl;
    for(int i=0; i<blocks.size(); ++i){
        for(int j=0; j<blanks.size(); ++j){
            if(!blank_flag[j] && !used_block_flag[blocks[i].second - 999]){
                if(blanks[j] == blocks[i].first){
                    blank_flag[j] = blocks[i].second;
                    used_block_flag[blocks[i].second - 999] = true;
                    answer += blanks[j].first;
                    break;
                }
            }
        }
    }

    return answer;
}

int main(void){
    cout << solution({
        {0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0},
        {1,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,1,1},
        {0,1,1,1,0,0,1,0,1,0,0,1,1,0,1,0,0,0},
        {0,0,0,0,1,1,0,0,1,1,0,1,0,0,1,0,0,0},
        {0,1,1,1,0,0,1,1,1,1,0,1,1,1,0,1,1,1},
        {1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0},
        {0,0,0,1,1,1,0,0,1,1,0,1,1,1,1,0,0,1},
        {1,1,1,0,0,0,1,1,0,0,1,0,0,0,0,1,1,0},
        {0,0,1,0,1,1,1,0,0,1,0,1,1,1,1,0,0,0},
        {1,1,0,1,1,0,1,1,1,1,0,1,0,0,0,1,1,1},
        {0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,1,0},
        {1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,0,1,0},
        {0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,1,0,0},
        {1,0,1,1,0,1,1,0,0,0,1,0,0,0,1,0,0,1},
        {1,0,0,1,1,0,0,1,1,1,0,1,1,1,0,1,1,0},
        {0,1,1,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0},
        {0,0,0,1,0,1,0,1,0,0,1,1,1,1,1,1,1,0},
        {0,1,0,1,1,0,0,1,0,1,0,0,0,0,0,0,1,0}}, {

        {1,1,1,1,1,1,0,1,0,1,1,0,0,1,0,0,1,0},
        {0,0,0,0,0,0,1,1,1,0,1,0,1,1,0,1,1,0},
        {1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,1,0,1},
        {1,1,0,1,1,1,0,1,0,1,0,1,1,0,1,0,0,1},
        {1,1,1,0,0,0,1,0,1,0,1,0,0,1,0,0,1,1},
        {0,0,0,1,1,1,0,1,1,1,0,1,1,0,1,0,0,0},
        {1,1,1,0,0,0,0,0,1,1,0,1,1,0,1,1,1,1},
        {0,0,1,0,1,1,0,1,0,0,1,0,0,1,0,0,0,0},
        {1,0,1,0,0,0,0,1,0,1,1,0,1,1,0,1,1,1},
        {1,0,1,0,1,1,1,1,0,1,1,0,0,0,1,1,1,0},
        {1,1,0,1,0,0,0,0,1,0,0,1,1,1,0,0,0,0},
        {0,0,1,1,1,1,0,1,1,0,1,0,0,0,1,1,0,1},
        {1,1,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,1},
        {1,1,0,0,1,1,1,0,1,1,0,1,0,1,0,1,0,1},
        {0,0,1,1,0,1,1,0,1,0,1,1,0,0,0,1,0,0},
        {1,1,1,0,1,0,0,1,0,1,1,0,0,1,0,1,0,1},
        {0,0,0,0,1,0,1,1,1,0,0,1,0,1,1,0,1,1},
        {0,1,1,1,1,0,0,1,0,0,1,1,0,1,0,0,1,1}});
    
    return 0;
}