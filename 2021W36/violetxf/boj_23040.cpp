/*
    누텔라 트리 (Easy)
    https://www.acmicpc.net/problem/23040
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;


long long parent[100001];
long long find(int x){
    if(parent[x]<0)return x;
    return parent[x] = find(parent[x]);
}
long long merge(int x, int y){
    long long x_root = find(x);
    long long y_root = find(y);
    if(x_root==y_root)return -parent[x_root];

    parent[x_root] += parent[y_root];
    parent[y_root] = x_root;
    return -parent[x_root];
}
long long get_size(int x){
    return -parent[find(x)];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>> con(n+1);
    vector<bool> isblack(n+1, false);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        con[a].push_back(b);
        con[b].push_back(a);
    }
    char rb[100001];
    cin>>rb;
    vector<int> blacks;
    vector<int> reds;
    for(int i=1;i<=n;i++){
        parent[i] = -1;
        if(rb[i-1]=='B'){
            isblack[i] = true;
            blacks.push_back(i);
        } else {
            reds.push_back(i);
        }
    }

    for(int k: reds){
        for(int near: con[k]){
            if(!isblack[near]){
                merge(k, near);
            }
        }
    }
    long long result = 0;
    for(int k: blacks){
        for(int near: con[k]){
            if(!isblack[near]){
                result+=get_size(near);
            }
        }
    }
    cout<<result;
}