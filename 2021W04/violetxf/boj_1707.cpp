#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);
    int K;
    cin>>K;    
    while(K--){
        vector<vector<int>> map(20001);
        int kind[20001]={0}; //unknown: 0
        bool result = true;
        int V, E;
        cin>>V>>E;
        for(int i=0;i<E;i++){
            int first, second;
            cin>>first>>second;
            map[first].push_back(second);
            map[second].push_back(first);
        }
        queue<pair<int,int>> q;
        for(int i=0;i<V;i++){
            if(kind[i])continue;
            q.push(make_pair(i, 1));
            kind[i] = 1;
            while(!q.empty()){
                int node = q.front().first;
                int node_kind = q.front().second;
                int next_kind;
                next_kind = 3-node_kind;
                q.pop();
                for(int k : map[node]){
                    if(kind[k]==node_kind){
                        result = false;
                        break;
                    }
                    if(kind[k])continue;
                    kind[k]=next_kind;
                    q.push(make_pair(k, next_kind));
                }
                if(!result)break;
            }
            if(!result)break;
        }
        if(result){
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
}