/*
    연산자 끼워넣기
    https://www.acmicpc.net/problem/14888
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000001
using namespace std;
int N;
int a[101];
int maxValue = -MAX;
int minValue = MAX;
void dfs(int cur, int sum, int pl, int mi, int mul, int di){
    if(cur==N){
        maxValue = max(maxValue, sum);
        minValue = min(minValue, sum);
        return;
    }
    if(pl>0)
        dfs(cur+1, sum+a[cur], pl-1, mi, mul, di);
    if(mi>0)
        dfs(cur+1, sum-a[cur], pl, mi-1, mul, di);
    if(mul>0)
        dfs(cur+1, sum*a[cur], pl, mi, mul-1, di);
    if(di>0)
        dfs(cur+1, sum/a[cur], pl, mi, mul, di-1);
}


int main(){
    cin>>N;
    int pl, mi, mul, di;
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    cin>>pl>>mi>>mul>>di;
    dfs(1, a[0], pl, mi, mul, di);
    cout<<maxValue<<"\n"<<minValue;
    //cout<<get_min(1, a[0], pl, mi, mul, di);

}