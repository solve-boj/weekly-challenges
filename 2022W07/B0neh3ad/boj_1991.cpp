#include <bits/stdc++.h>
using namespace std;

class Tree{
public:
    int N;
    vector<int> lc, rc;

    Tree(): N(0){}
    Tree(int n): N(n){
        lc.resize(n, -19);
        rc.resize(n, -19);
    }

    void addChildren(int p, int l, int r){
        lc[p] = l;
        rc[p] = r;
    }

    void preorder(int root){
        cout << char(root + 'A');
        if(lc[root] != -19) preorder(lc[root]);
        if(rc[root] != -19) preorder(rc[root]);
    }
    void inorder(int root){
        if(lc[root] != -19) inorder(lc[root]);
        cout << char(root + 'A');
        if(rc[root] != -19) inorder(rc[root]);
    }
    void postorder(int root){
        if(lc[root] != -19) postorder(lc[root]);
        if(rc[root] != -19) postorder(rc[root]);
        cout << char(root + 'A');
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    Tree t(n);
    for(int i=0; i<n; ++i){
        char p, l, r;
        cin >> p >> l >> r;
        t.addChildren(p-'A', l-'A', r-'A');
    }

    t.preorder(0);
    cout << "\n";
    t.inorder(0);
    cout << "\n";
    t.postorder(0);

    return 0;
}