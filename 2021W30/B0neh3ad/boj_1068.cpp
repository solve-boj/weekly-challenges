/*
    트리
    https://www.acmicpc.net/problem/1068
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Tree{
public:
    int tsize, root;
    vector<int> parent;
    vector<vector<int> > children;

    Tree(): tsize(0){}
    Tree(int n): tsize(n){
        parent.resize(n);
        children.resize(n);
    }

    void addEdge(int p, int c){
        parent[c] = p;
        if(p != -1){ children[p].push_back(c); }
        else{ root = c; }
    }

    int solution(int rmval){
        if(rmval == root){ return 0; }

        int ans = 0;
        queue<int> q;
        vector<bool> visited(tsize, false);

        visited[root] = true;
        q.push(root);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(children[curr].size() == 0){ ++ans; } // leaf node인 경우
            else{
                for(int next: children[curr]){
                    if(next != rmval && !visited[next]){ // 제거된 node 제외 방문 안 한 자식 노드 있다면
                        visited[next] = true; // 방문
                        q.push(next);
                    }
                    else if(next == rmval && children[curr].size() == 1){ // node의 제거로 인해 leaf node가 되는 경우
                        ++ans;
                    }
                }
            }
        }

        return ans;
    }
};

int main(void){
    int N;
    cin >> N;

    Tree t(N);
    int temp;
    for(int i=0; i<N; ++i){
        cin >> temp;
        t.addEdge(temp, i);
    }

    int rm;
    cin >> rm;

    cout << t.solution(rm);
    return 0;
}