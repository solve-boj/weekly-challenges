/*
    거리두기 확인하기
    https://programmers.co.kr/learn/courses/30/lessons/81302
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> dir[4] = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};
queue<pair<pair<int, int>, int>> q;

bool bfs(vector<string> place, pair<int, int> start) {
    vector<string> vis = {"00000", "00000", "00000", "00000", "00000"};
    int res = true;
    vis[start.first][start.second] = '1';
    q.push(make_pair(start, 0));
    while(!q.empty()) {
        pair<int, int> coord = q.front().first;
        int dist = q.front().second;
        q.pop();
        if (dist > 0 && dist <= 2 && place[coord.first][coord.second] == 'P') {
            res = false;
        }
        for(int i=0;i<4;i++) {
            pair<int, int> changed = make_pair(coord.first + dir[i].first, coord.second + dir[i].second);
            if(changed.first >= 0 && changed.first < 5 && changed.second >= 0 && changed.second < 5
            && place[changed.first][changed.second] != 'X' && vis[changed.first][changed.second] != '1') {
                //printf("%d %d %d\n", changed.first, changed.second, dist+1);
                vis[changed.first][changed.second] = '1';
                q.push(make_pair(changed, dist+1));
            }
        }
    }
    //printf("%s\n", res?"true":"false");
    return res;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0;i<places.size();i++) {
        //printf("case %d\n", i+1);
        bool flag = true;
        for(int j=0;j<5;j++) {
            for(int k=0;k<5;k++) {
                if(places[i][j][k] == 'P') {
                    bool res = bfs(places[i], make_pair(j, k));
                    //printf("-----------\n");
                    if(!res) flag = false;
                }
            }
        }
        answer.push_back((flag)?1:0);
    }

    return answer;
}


int main() {
    vector<vector<string>> v ={{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
    {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
    {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};
    vector<int> ans = solution(v);
    for(int i=0;i<ans.size();i++) {
        printf("%d ", ans[i]);
    }
}

// keyword: BFS
// 시간복잡도: O(N A^2 B^2) (N은 테케 수, A는 가로 길이, B는 세로 길이)
/*
idea: 각 case의 각 P에 대해 bfs 돌리고 택시거리가 2 이하인 지점에 P 있으면 바로 false
*/