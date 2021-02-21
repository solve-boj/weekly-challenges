/*
    두 용액
    https://www.acmicpc.net/problem/2470
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int arr[100001];
    int N;
    int minval = 2000000000;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr,arr+N);
    int left = 0;
    int right = N-1;
    int rsltLeft = 0;
    int rsltRight = 0;
    while(left<right){
        int sum = arr[left]+arr[right];
        if(abs(minval)>abs(sum)){
            minval = sum;
            rsltLeft = left;
            rsltRight = right;
        }
        if(sum<0){
            left++;
        } else {
            right--;
        }
    }
    cout<<arr[rsltLeft]<<" "<<arr[rsltRight];

}