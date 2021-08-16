/*
    집합의 표현
    https://www.acmicpc.net/problem/1717
*/
#include <iostream>
using namespace std;
int parent[1000001];
int find(int a){
    if(parent[a]<0) return a;
    return parent[a] = find(parent[a]);
}
void merge(int a, int b){
    int a_root = find(a);
    int b_root = find(b);
    if(a_root == b_root) return;
    parent[a_root] = b_root;
}
int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        parent[i] = -1;
    }
    while(m--){
        int mode, a, b;
        cin>>mode>>a>>b;
        if(!mode){ //merge
            merge(a,b);
        } else { //check
            if(find(a) == find(b))cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}