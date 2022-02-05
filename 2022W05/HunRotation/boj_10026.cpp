/*
    적록색약
    https://www.acmicpc.net/problem/10026
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
char board[101][101];
bool vis[100][100], vis2[100][100];
const pair<int, int> dir[4] = {{1, 0},{-1, 0},{0, 1},{0, -1}};
stack<pair<int, int>> st;
int cnt = 0, cnt2 = 0;

bool colorblind(char c) {
    return c=='B';
}

int main() {
    char cur;
    pair<int, int> temp;
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%s", board[i]);
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if (!vis[i][j]) {
                st.push({i, j});
                vis[i][j] = true;
                cur = board[i][j];
                ++cnt;
                while(!st.empty()) {
                    temp = st.top();
                    st.pop();
                    for(pair<int, int> dxy: dir) {
                        if(temp.first+dxy.first>=0 && temp.first+dxy.first<N &&
                        temp.second+dxy.second>=0 && temp.second+dxy.second<N &&
                        !vis[temp.first+dxy.first][temp.second+dxy.second] &&
                        board[temp.first+dxy.first][temp.second+dxy.second] == cur) {
                            st.push({temp.first+dxy.first, temp.second+dxy.second});
                            vis[temp.first+dxy.first][temp.second+dxy.second] = true;
                        }
                    }
                }
            }
            if (!vis2[i][j]) {
                st.push({i, j});
                vis2[i][j] = true;
                cur = board[i][j];
                ++cnt2;
                while(!st.empty()) {
                    temp = st.top();
                    st.pop();
                    for(pair<int, int> dxy: dir) {
                        if(temp.first+dxy.first>=0 && temp.first+dxy.first<N &&
                        temp.second+dxy.second>=0 && temp.second+dxy.second<N &&
                        !vis2[temp.first+dxy.first][temp.second+dxy.second] &&
                        colorblind(board[temp.first+dxy.first][temp.second+dxy.second]) == colorblind(cur)) {
                            st.push({temp.first+dxy.first, temp.second+dxy.second});
                            vis2[temp.first+dxy.first][temp.second+dxy.second] = true;
                        }
                    }
                }
            }
        }
    }
    printf("%d %d", cnt, cnt2);
}