/*
    등수 매기기
    https://www.acmicpc.net/problem/2012
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int> est(N);
    for(int i=0;i<N;i++){
        cin>>est[i];
    }
    sort(est.begin(), est.end());
    long long answer = 0;
    for(int i=1;i<=N;i++){
        answer+=abs(est[i-1]-i);
    }
    cout<<answer;
}