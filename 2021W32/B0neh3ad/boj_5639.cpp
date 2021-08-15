/*
    이진 검색 트리
    https://www.acmicpc.net/problem/5639
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
public:
    int data;
    Node* lc;
    Node* rc;

    Node(): data(0), lc(nullptr), rc(nullptr){}
    Node(int n, Node* lc1, Node* rc1): data(n), lc(lc1), rc(rc1){}
};

class Tree{
public:
    int tsize;
    Node* root;

    Tree(): tsize(0), root(nullptr){}

    ~Tree(){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            if(curr->lc != nullptr){ q.push(curr->lc); }
            if(curr->rc != nullptr){ q.push(curr->rc); }

            delete curr;
        }
    }

    void push(int val){
        if(tsize == 0){ root = new Node(val, nullptr, nullptr); }
        else{
            Node* curr = root;
            while(true){ // leaf node까지만!
                if(val < curr->data){
                    if(curr->lc == nullptr){
                        curr->lc = new Node(val, nullptr, nullptr);
                        break;
                    }
                    curr = curr->lc;
                }
                else{
                    if(curr->rc == nullptr){
                        curr->rc = new Node(val, nullptr, nullptr);
                        break;
                    }
                    curr = curr->rc;
                }
            }
        }
        ++tsize;
    }

    void postorder(Node* curr){
        if(curr->lc != nullptr){ postorder(curr->lc); }
        if(curr->rc != nullptr){ postorder(curr->rc); }
        cout << curr->data << '\n';
    }
};

int main(void){
    int node;
    Tree t;

    while(cin >> node)
        t.push(node);

    t.postorder(t.root);

    return 0;
}
/*
    EOF 연습!
    왜 틀렸었는지 이해가 안 간다...
    19993364번 코드: upper_bound를 이용한 배열 탐색.
    root node에 대해 upper_bound 적용 -> 오른쪽 subtree의 root node iterator 얻음
    이를 [root+1, r_sub_root-1] [r_sub_root, end]에 대해 각각 재귀적으로 적용
*/