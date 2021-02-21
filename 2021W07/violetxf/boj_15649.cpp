/*
    N과 M (1)
    https://www.acmicpc.net/problem/15649
*/
#include <iostream>
#include <vector>
using namespace std;
int N,M;
bool used[9];
void solve(vector<int>& vec, int cnt, int current){
    if(cnt==M){
        for(int k:vec){
            cout<<k<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=N;i++){
        if(!used[i]){
            used[i] = true;
            vec.push_back(i);
            solve(vec, cnt+1, i+1);
            vec.pop_back();
            used[i] = false;
        }
    }
}
int main(){
    vector<int> vec;
    cin>>N>>M;
    solve(vec, 0, 1);
}