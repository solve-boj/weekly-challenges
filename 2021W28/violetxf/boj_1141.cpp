/*
    접두사
    https://www.acmicpc.net/problem/1141
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string first, string second){
    return first.size()<second.size();
}
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<string>str(n);
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    sort(str.begin(), str.end(), cmp);
    int prefixes = 0;
    for(int i=0;i<n;i++){
        for(int k=i+1;k<n;k++){
            if(str[k].find(str[i])==0){
                prefixes++;
                break;
            }
        }
    }
    cout<<n-prefixes;
}