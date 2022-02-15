/*
    DSLR
    https://www.acmicpc.net/problem/9019
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

vector<bool> vis(10000, false);
int T, A, B;
queue<pair<int, string>> q;
int n[4];
char command[4] = {'D', 'S', 'L', 'R'};
pair<int, string> temp;
string t;

int main() {
    scanf("%d", &T);
    for(int i=0;i<T;i++) {
        fill(vis.begin(), vis.end(), false);
        scanf("%d%d", &A, &B);
        q.push({A, ""});
        vis[A] = true;
        while(!q.empty()) {
            temp = q.front();
            q.pop();
            if(temp.first == B) {
                cout << temp.second << endl;
                while(!q.empty()) q.pop();
                break;
            }
            n[0] = (temp.first*2)%10000;
            n[1] = (temp.first+9999)%10000;
            n[2] = temp.first/1000 + temp.first%1000*10;
            n[3] = temp.first%10*1000 + temp.first/10;
            for(int j=0;j<4;j++) {
                if(!vis[n[j]]) {
                    t = temp.second + command[j];                               
                    q.push({n[j], t});
                    vis[n[j]] = true;
                }
            }
        }
    }
}