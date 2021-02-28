/*
    N과 M (3)
    https://www.acmicpc.net/problem/15651
*/
#include <iostream>
#include <vector>
using namespace std;
int N,M;
void f(vector<int>& vec, int left){
    if(left==0){
        for(int k:vec){
            cout<<k<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=N;i++){
        vec.push_back(i);
        f(vec, left-1);
        vec.pop_back();
    }

}
int main(){
    
    cin>>N>>M;
    vector<int> vec;
    f(vec, M);
}