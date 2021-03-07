/*
    오큰수
    https://www.acmicpc.net/problem/17298
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    vector<pair<int,int>> arr;
    
    int N;
    cin>>N;
    vector<int> answer(N, -1);
    int k;
    cin>>k;
    int idx = 0;
    arr.push_back({k,0});
    for(int i=1;i<N;i++){
        cin>>k;
        if(arr.back().first<k){
            while(!arr.empty()){
                int back = arr.back().first;
                int pos = arr.back().second;
                if(back>=k)break;
                answer[pos] = k;
                arr.pop_back();


            }
        }
        
        arr.push_back({k,i});

    }
    for(int k: answer){
        cout<<k<<" ";
    }

}