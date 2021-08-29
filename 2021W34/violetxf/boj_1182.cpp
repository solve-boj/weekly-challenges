/*
    부분수열의 합
    https://www.acmicpc.net/problem/1182
*/
#include <iostream>
#include <vector>
using namespace std;
int answer = 0;
int n;
int s;

void find(vector<int> &arr, int sum, int idx){
    sum+=arr[idx];
    if(idx==n){
        return;
    }
    if(sum==s){
        answer++;
    }
    
    find(arr, sum-arr[idx], idx+1);
    find(arr, sum, idx+1);

}
int main(){

    cin>>n;
    
    cin>>s;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    find(arr, 0, 0);
    cout<<answer;
}