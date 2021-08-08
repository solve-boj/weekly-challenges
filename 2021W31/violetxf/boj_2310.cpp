#include <iostream>
#include <vector>
using namespace std;
bool answer = false;
void dfs(int n, vector<vector<int>> & way, vector<char> & type, vector<int> & cost, int room, int money, vector<bool> & visited){
    if(type[room] == 'L'){
        if(cost[room]>money){
            money = cost[room];
        }
    } else if(type[room] == 'T'){
        if(cost[room]>money){
            return;
        } else{
            money-=cost[room];
        }
    }
    if(room == n){
        answer = true;
        return;
    }
    visited[room] = true;
    for(int next: way[room]){
        if(!visited[next]){ 
            dfs(n, way, type, cost, next, money, visited); 
        }
    }
    visited[room] = false;
}
int main(){
    while(true){
        answer = false;
        int n;
        cin>>n;
        if(n==0)break;
        vector<vector<int>> way(n);
        vector<char> types;
        vector<int> costs;
        vector<bool> visited(n);
        for(int i=0;i<n;i++){
            char type;
            int cost;
            cin>>type;
            cin>>cost;
            costs.push_back(cost);
            types.push_back(type);
            while(true){
                int input;
                cin>>input;
                if(input==0)break;
                way[i].push_back(input-1);
            }
        }
        visited[0] = true;
        dfs(n-1, way, types, costs, 0, 0, visited);
        if(answer){
            cout<<"Yes\n";
        } else {
            cout<<"No\n";
        }
    }
}