/*
    ATM
    https://www.acmicpc.net/problem/11399
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    priority_queue<int, vector<int>, greater<int>> p;
    cin>>N;
    for(int i=0;i<N;i++){
        int temp;
        cin>>temp;
        p.push(temp);
    }
    int total=0;
    while(N){
        total+=p.top()*N;
        p.pop();
        N--;
    }
    cout<<total;
}