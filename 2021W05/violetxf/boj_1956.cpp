/*
    운동
    https://www.acmicpc.net/problem/1956
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);
    vector<vector<int>> dist(401, vector<int>(401, INF));
    int V, E;
    cin>>V>>E;
    while(E--){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b] = c;
    }
    for(int k=1;k<=V;k++){
        for(int i=1;i<=V;i++){
            for(int j=1;j<=V;j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    int sum = INF;
    for(int i=1;i<=V;i++){
        for(int k=1;k<=V;k++){
            if(dist[i][k]!=INF && dist[k][i]!=INF){
                sum = min(sum, dist[i][k]+dist[k][i]);
            }
        }
    }
    if(sum==INF){
        cout<<-1;
    } else {
        cout<<sum;
    }
}