/*
    트리 순회
    https://www.acmicpc.net/problem/1991
*/
#include <iostream>
#include <vector>
using namespace std;

class Tree{
public:
    int tsize;
    vector<int> parent;
    vector<int> lchild;
    vector<int> rchild;

    Tree():tsize(0) {}
    Tree(int n):tsize(n){
        parent.resize(n, -1);
        lchild.resize(n, -1);
        rchild.resize(n, -1);
    }

    void addEdge(int curr, int lc, int rc){
        if(lc >= 0){
            lchild[curr] = lc;
            parent[lc] = curr;
        }
        if(rc >= 0){
            rchild[curr] = rc;
            parent[rc] = curr;
        }
    }

    void preorder(int curr){
        cout << char(curr + 65);
        if(lchild[curr] != -1){ preorder(lchild[curr]); }
        if(rchild[curr] != -1){ preorder(rchild[curr]); }
    }

    void inorder(int curr){
        if(lchild[curr] != -1){ inorder(lchild[curr]); }
        cout << char(curr + 65);
        if(rchild[curr] != -1){ inorder(rchild[curr]); }
    }

    void postorder(int curr){
        if(lchild[curr] != -1){ postorder(lchild[curr]); }
        if(rchild[curr] != -1){ postorder(rchild[curr]); }
        cout << char(curr + 65);
    }
};

int main(void){
    int N;
    cin >> N;

    Tree t(N);
    char p, c1, c2;
    for(int i=0; i<N; ++i){
        cin >> p >> c1 >> c2;
        t.addEdge(int(p-65), int(c1-65), int(c2-65));
    }

    t.preorder(0);
    cout << '\n';
    t.inorder(0);
    cout << '\n';
    t.postorder(0);
    
    return 0;
}