/*
    공유기 설치
    https://www.acmicpc.net/problem/2110
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, C;
    vector<int> pos;
    cin>>N>>C;
    for(int i=0;i<N;i++){
        int input;
        cin>>input;
        pos.push_back(input);
    }
    sort(pos.begin(), pos.end());
    int start = 1;
    int end = pos[N-1] - pos[0];
    int answer = 0;
    while(start<=end){
        int mid = (start+end)/2;
        int tmp = pos[0];
        int count = 1;
        for(int i=1;i<N;i++){
            if(pos[i]-tmp>=mid){
                count++;
                tmp = pos[i];
            }
        }
        if(count>=C){
            answer = max(answer, mid);
            start = mid+1;
        } else {
            end = mid-1;
        }
    }
    cout<<answer;
    
}