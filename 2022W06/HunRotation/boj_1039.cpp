/*
    교환
    https://www.acmicpc.net/problem/1039
*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, K, M;
string S;
queue<string> q[11];
vector<bool> vis(1000001);
int maxnum = -1;

int main() {
    string temp;
    scanf("%d %d", &N, &K);
    S = to_string(N);
    M = S.size();
    q[0].push(S);
    for(int i=0;i<K;i++) {
        fill(vis.begin(), vis.end(), false);
        while(!q[i].empty()) {
            temp = q[i].front();
            q[i].pop();
            for(int j=0;j<M-1;j++) {
                for(int k=j+1;k<M;k++) {
                    string newstr = temp;
                    swap(newstr[j], newstr[k]);
                    if(!vis[stoi(newstr)] && newstr[0] != '0') {
                        q[i+1].push(newstr);
                        vis[stoi(newstr)] = true;
                    }
                }
            }
        }
        while(!q[K].empty()) {
            maxnum = (maxnum<stoi(q[K].front()))?stoi(q[K].front()):maxnum;
            q[K].pop();
        }
    }
    printf("%d", maxnum);
}