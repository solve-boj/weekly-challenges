/*
    수들의 합 2
    https://www.acmicpc.net/problem/2003
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N,M;
    cin>>N>>M;
    vector<int> sum(N+1);
    sum[0] = 0;
    for(int i=1;i<=N;i++){
        cin>>sum[i];
        sum[i]+=sum[i-1];
    }
    int count = 0;
    for(int left=1;left<=N;left++){
        for(int right = left;right<=N;right++){
            int res = sum[right] - sum[left-1];
            if(res==M){
                count++;
            }
        }
    }
    cout<<count;
}