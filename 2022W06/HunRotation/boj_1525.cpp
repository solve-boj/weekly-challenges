/*
    퍼즐
    https://www.acmicpc.net/problem/1525
*/

#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

queue<pair<int, int>> q;
set<int> visited;
int board = 123456780, temp;
int refer = 0;
vector<int> dir = {-1, -3, 1, 3};


int main() {
    int a, t, p;
    string s;
    for(int i=0;i<9;i++) {
        scanf("%d", &a);
        refer *= 10;
        refer += a;
    }
    q.push({board, 0});
    while(!q.empty()) {
        board = q.front().first;
        t = q.front().second;
        if (board == refer) {
            printf("%d", t);
            return 0;
        }
        q.pop();
        visited.insert(board);
        for(int i=0;i<dir.size();i++) {
            s = (board<100000000)?"0":"";
            s += to_string(board);
            //cout << "s: "<< s << endl;
            p = s.find('0');
            if(p+dir[i]>=0 && p+dir[i] < 9) {
                if((dir[i]==1 && p%3==2) || (dir[i]==-1 && p%3==0)) continue;
                swap(s[p], s[p+dir[i]]);
                //cout << "ss: "<< s << endl;
                if(visited.find(stoi(s)) == visited.end()) q.push({stoi(s), t+1});
            }
        }
    }
    if(q.empty()) printf("-1");
}