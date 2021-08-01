/*
    프린터 큐
    https://www.acmicpc.net/problem/1966
*/
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,M;
        queue<pair<int, bool>> q;
        vector<int> v;
        cin>>N>>M;
        for(int i=0;i<N;i++){
            bool mark = (i==M);
            int priority;
            cin>>priority;
            v.push_back(priority);
            q.push({priority, mark});
        }
        sort(v.begin(), v.end());
        int count = 0;
        while(!q.empty()){
            pair<int, bool> p = q.front();
            q.pop();
            if(p.first == v.back()){
                count++;
                v.pop_back();
                if(p.second){
                    break;
                }
            } else {
                q.push(p);
            }
        }
        cout<<count<<"\n";
    }
}