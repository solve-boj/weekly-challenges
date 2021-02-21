/*
    부분합
    https://www.acmicpc.net/problem/1806
*/
#include <iostream>
using namespace std;
int main(){
    int N, S;
    cin>>N>>S;
    int arr[100001];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int sum = arr[0];
    int left = 0;
    int right = 0;
    int minLen = 100001;
    while(left<=right){
        int next = arr[right+1];
        int tail = arr[left];
        if(sum<S){
            if(right==N-1)break;
            right++;
            sum+=next;
        } else {
            minLen = min(minLen, right-left+1);
            if(sum-tail>=S){
                left++;
                sum-=tail;
            } else {
                if(right==N-1)break;
                right++;
                sum+=next;
            }
        }
    }
    if(minLen==100001)cout<<0;
    else cout<<minLen;
}