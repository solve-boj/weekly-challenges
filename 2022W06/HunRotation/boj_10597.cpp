/*
    순열장난
    https://www.acmicpc.net/problem/10597
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
bool vis[51];
vector<int> seq;
int N;
bool done = false;

void f(int pos, int cnt) {
    if(done) return;
    if(pos==str.size() && cnt==N) {
        for(int i: seq) {
            printf("%d ", i);
        }
        done = true;
        return;
    }
    else if(pos>=str.size() || cnt==N) return;
    int temp = stoi(str.substr(pos, 1));
    if(!temp) return;
    if(temp<=N && !vis[temp]) {
        vis[temp] = true;
        seq.push_back(temp);
        f(pos+1, cnt+1);
        vis[temp] = false;
        seq.pop_back();
    }
    temp = stoi(str.substr(pos, 2));
    if(temp<=N && !vis[temp]) {
        vis[temp] = true;
        seq.push_back(temp);
        f(pos+2, cnt+1);
        vis[temp] = false;
        seq.pop_back();
    }
}   

int main() {
    cin >> str;
    if(str.size() < 10) N = str.size();
    else N = 9 + (str.size()-9)/2;
    f(0, 0);
}

