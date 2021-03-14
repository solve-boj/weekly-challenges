/*
    랜선 자르기
    https://www.acmicpc.net/problem/1654
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long len[10001];
int K, N;
long long calc(long long cut){
    long long result = 0;
    for(int i=0;i<K;i++){
        result += len[i]/cut;
    }
    return result;
}
int main(){
    
    cin>>K>>N;
    long long end = 0;
    
    for(int i=0;i<K;i++){
        cin>>len[i];
        end = max(end, len[i]);
    }
    long long start = 1;
    long long max_cut = 0;
    
    while(start<=end){
        long long cut = (start+end)/2;
        long long num = calc(cut);
        if(num>=N){
            max_cut = max(max_cut, cut);
            start = cut + 1;

        } else {
            //decrease
            end = cut - 1;
        }
    }
    cout<<max_cut;
}