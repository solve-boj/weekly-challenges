/*
    한동이는 공부가 하기 싫어!
    https://www.acmicpc.net/problem/3182
*/
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int next[1001];
    bool visited[1001];
    for(int i=0;i<n;++i){
        int recommend;
        cin>>recommend;
        recommend--;
        next[i] = recommend;
        
    }
    int max = 0;
    int idx = 0;
    for(int i=0;i<n;++i){
        for(int k=0;k<n;++k){
            visited[k] = false;
        }
        int current = i;
        int count = 0;
        while(!visited[current]){
            visited[current] = true;
            current= next[current];
            count++;
        }
        if(count>max){
            max = count;
            idx = i;
        }
    }
    cout<<idx+1;
}