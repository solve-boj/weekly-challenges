/*
    회의실 배정
    https://www.acmicpc.net/problem/1931
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(pair<int,int>a, pair<int,int>b){
    if(a.second==b.second)return a.first<b.first;
    return a.second<b.second;
}
int main(){
    int N;
    cin>>N;
    vector<pair<int, int>> map;
    while(N--){
        int start,end;
        cin>>start>>end;
        map.push_back({start,end});
    }
    sort(map.begin(), map.end(), comp);
    int tail = 0;
    int result = 0;
    for(auto iter = map.begin(); iter!=map.end();++iter){
        if(tail<=(*iter).first){
            tail = (*iter).second;
            result++;
        }
    }
    cout<<result;
    
}