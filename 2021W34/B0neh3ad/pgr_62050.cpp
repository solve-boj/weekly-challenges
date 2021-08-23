/*
    지형 이동
    https://programmers.co.kr/learn/courses/30/lessons/62050
*/
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int find(int num, vector<int>& p){
    if(num == p[num]){ return num; }
    return p[num] = find(p[num], p);
}

bool merge(int lhs, int rhs, vector<int>& p){
    lhs = find(lhs, p);
    rhs = find(rhs, p);
    if(lhs == rhs){ return false; }
    p[rhs] = lhs;
    return true;
}

bool cmp(const pair<pii, int>& lhs, const pair<pii, int>& rhs){ return lhs.second < rhs.second; }
int isInside(int y, int x, int len){ return y*(len-1-y) >= 0 && x*(len-1-x) >= 0; }

int solution(vector<vector<int>> land, int height) {
    size_t n = land.size();
    int answer = 0;
    int dy[4] = {0, -1, 0, 1}, dx[4] = {1, 0, -1, 0};

    map<pii, int> min_diff;
    vector<vector<int> > check(n);
    for(int i=0; i<n; ++i){ check[i].resize(n, 0); }

    int area_num = 0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(!check[i][j]){
                ++area_num;
                queue<pii> q;

                check[i][j] = area_num;
                q.push(pii(i, j));
                while(!q.empty()){
                    int curr_y = q.front().first;
                    int curr_x = q.front().second;
                    q.pop();
                    for(int k=0; k<4; ++k){
                        int next_y = curr_y + dy[k];
                        int next_x = curr_x + dx[k];
                        if(isInside(next_y, next_x, n)){
                            int diff = abs(land[next_y][next_x] - land[curr_y][curr_x]);
                            // 미탐색 and 탐색 가능 -> 탐색
                            if(!check[next_y][next_x]){
                                if(diff <= height){
                                    check[next_y][next_x] = area_num;
                                    q.push(pii(next_y, next_x));
                                }
                            }
                            // 다른 영역 -> 경계
                            else if(check[next_y][next_x] != area_num){
                                pii boundary = {check[next_y][next_x], area_num};
                                if(!min_diff.insert({boundary, diff}).second)
                                    min_diff[boundary] = min(min_diff[boundary], diff);
                            }
                        }
                    }
                }
            }
        }
    }

    vector<int> parent(area_num+1);
    vector<pair<pii, int> > sorted_min_diff(min_diff.begin(), min_diff.end());
    
    for(int i=0; i<=area_num; ++i){ parent[i] = i; }
    sort(sorted_min_diff.begin(), sorted_min_diff.end(), cmp);

    int ladder_cnt = 0;
    for(auto& diff: sorted_min_diff){
        int u = diff.first.first;
        int v = diff.first.second;
        if(merge(u, v, parent)){
            answer += diff.second;
            if(++ladder_cnt == area_num - 1){ break; }
        }
    }

    return answer;
}
/*
    BFS(DFS) + MST(나는 크루스칼으로 함)
    시간복잡도는 대충 O(N^2)쯤 되겠지 뭐
*/