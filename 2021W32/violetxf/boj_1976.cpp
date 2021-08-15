/*
    여행 가자
    https://www.acmicpc.net/problem/1976
*/
#include <iostream>
using namespace std;
int parent[201];
int find(int x){
    if(parent[x]<0)return x;
    return parent[x] = find(parent[x]);
}
void merge(int x, int y){
    int x_root = find(x);
    int y_root = find(y);
    if(x_root == y_root) return;
    parent[x_root] = y_root;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int m;
    cin>>m;
    for(int i=1;i<=n;i++){
        parent[i] = -1;
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            bool is_connected;
            cin>>is_connected;
            if(is_connected){
                merge(i, k);
            }
        }
    }
    int root;
    bool result = true;
    int city;
    cin>>city;
    root=find(city);
    for(int i=1;i<m;i++){
        int city;
        cin>>city;
        if(root != find(city)){
            result = false;
            break;
        }
    }
    if(result){
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }

}