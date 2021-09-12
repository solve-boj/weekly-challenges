/*
    자연수 색칠하기
    https://www.acmicpc.net/problem/23048
*/
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int colored[500001] = {0};
    colored[1] = 1;
    int result = 1;
    int colorId = 2;
    for(int i=2;i<=n;i++){
        if(!colored[i]){
            ++result;
            
            for(int k=i; k<=n; k+=i){
                colored[k] = colorId;
            }
            ++colorId;
        }
    }
    cout<<result<<"\n";
    for(int i=1;i<=n;i++){
        cout<<colored[i]<<" ";
    }
}