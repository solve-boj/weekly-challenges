/*
    친구비
    https://www.acmicpc.net/problem/16562
*/
#include <iostream>
using namespace std;
int A[10001];
int parent[10001];
int find(int x){
    if(parent[x]<0) return x;
    return parent[x] = find(parent[x]);
}
void merge(int x, int y){
    int x_root = find(x);
    int y_root = find(y);
    if(x_root == y_root) return;
    if(A[x_root] < A[y_root]) parent[y_root] = x_root;
    else parent[x_root] = y_root;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>A[i];
        parent[i] = -1;
    }
    for(int i=1;i<=m;i++){
        int v,w;
        cin>>v>>w;
        merge(v,w);
    }
    int answer = 0;
    for(int i=1;i<=n;i++){
        if(parent[i] == -1){
            answer+=A[i];
        }
    }
    if(answer>k)cout<<"Oh no\n";
    else cout<<answer;


}