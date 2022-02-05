/*
    음식물 피하기
    https://www.acmicpc.net/problem/1743
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N, M, K, r, c;
bool board[101][101];
pair<int, int> dir[4] = {{1, 0},{-1, 0},{0, 1},{0, -1}};
stack<pair<int, int>> st;
int maxsize = 0;

int main() {
    int cnt;
    pair<int, int> temp;
    cin >> N >> M >> K;
    for(int i=0;i<K;i++) {
        cin >> r >> c;
        board[r][c] = true;
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cnt = 0;
            if (!board[i][j]) continue;
            st.push({i, j});
            board[i][j] = false;
            ++cnt;
            while(!st.empty()) {
                temp = st.top();
                st.pop();
                for(pair<int, int> dxy: dir) {
                    if(temp.first+dxy.first>=1 && temp.first+dxy.first<=N &&
                    temp.second+dxy.second>=1 && temp.second+dxy.second<=M &&
                    board[temp.first+dxy.first][temp.second+dxy.second]) {
                        st.push({temp.first+dxy.first, temp.second+dxy.second});
                        board[temp.first+dxy.first][temp.second+dxy.second] = false;
                        ++cnt;
                    }
                }
            }
            maxsize = (cnt>maxsize)?cnt:maxsize;
        }
    }
    cout << maxsize;
}