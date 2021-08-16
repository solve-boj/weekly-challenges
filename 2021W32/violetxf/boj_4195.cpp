/*
    친구 네트워크
    https://www.acmicpc.net/problem/4195
*/
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
int parent[200001];

int find(int x){
    if(parent[x]<0)return x;
    return parent[x] = find(parent[x]);
}
int merge(int x, int y){
    int x_root = find(x);
    int y_root = find(y);
    if(x_root==y_root)return -parent[x_root];

    parent[x_root] += parent[y_root];
    parent[y_root] = x_root;
    return -parent[x_root];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        for(int i=1;i<200001;i++){
            parent[i] = -1;
        }
        int f;
        cin>>f;
        unordered_map<string, int> name;
        int idx = 1;
        
        while(f--){
            string a,b;
            cin>>a>>b;
            if(name.count(a)==0)
                name[a] = idx++;
            if(name.count(b)==0)
                name[b] = idx++;
            cout<<merge(name[a], name[b])<<"\n";
        }
    }
}