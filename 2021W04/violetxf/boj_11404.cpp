/*
    플로이드
    https://www.acmicpc.net/problem/11404
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> dist(101, vector<int>(101, INF));

    for(int i=0;i<m;i++){
        int from,to,cost;
        cin>>from>>to>>cost;
        
        dist[from-1][to-1] = min(dist[from-1][to-1],cost);
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]!=INF && dist[k][j] != INF){
                    if(dist[i][k]+dist[k][j]<dist[i][j]){
                        dist[i][j] = dist[i][k]+dist[k][j];
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int res = dist[i][j];
            if(res>=INF||i==j)cout<<"0 ";
            else cout<<res<<" ";
        }
        cout<<"\n";
    }
}