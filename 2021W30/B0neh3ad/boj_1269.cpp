/*
    대칭 차집합
    https://www.acmicpc.net/problem/1269
*/
#include <iostream>
#include <vector>
using namespace std;

class Listnode{
public:
    int value;
    Listnode* lc;
    Listnode* rc;

    Listnode(): value(0), lc(nullptr), rc(nullptr){}
    Listnode(int value1, Listnode* lc1, Listnode* rc1): value(value1), lc(lc1), rc(rc1){}
};

class BST{
public:
    int tsize;
    Listnode* root;

    BST(): tsize(0), root(nullptr) {}
    BST(int n): tsize(n), root(new Listnode(-1, nullptr, nullptr)) {}

    void beginOrder(){
        order(root);
        cout << '\n';
    }

    void insert(int num){
        if(root->value == -1){ root->value = num; }
        else{
            Listnode* curr = root;
            while(true){
                if(curr->value < num){ // 현재 node보다 더 큰 값인 경우 -> 우측 삽입
                    if(!(curr->rc)) { curr->rc = new Listnode(num, nullptr, nullptr); break; }
                    else{ curr = curr->rc; }
                }
                else{
                    if(!(curr->lc)){ curr->lc = new Listnode(num, nullptr, nullptr); break; }
                    else{ curr = curr->lc; }
                }
            }
        }
    }

    int find(int num){
        Listnode* curr = root;
        while(curr){
            if(curr->value == num){ return 1; }
            else if(curr->value > num){ curr = curr->lc; }
            else{ curr = curr->rc; }
        }
        return 0;
    }
private:
    void order(Listnode *curr){
        if(curr->lc){ order(curr->lc); }
        cout << curr->value << " ";
        if(curr->rc){ order(curr->rc); }
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int an, bn;
    cin >> an >> bn;

    int a[an];
    for(int i=0; i<an; ++i)
        cin >> a[i];

    BST t(an);
    for(int i=0; i<an; ++i)
        t.insert(a[i]);

    int temp, ans = 0;
    for(int i=0; i<bn; ++i){
        cin >> temp;
        ans += t.find(temp);
    }
    
    ans = an + bn - 2 * ans;
    cout << ans;
    return 0;
}