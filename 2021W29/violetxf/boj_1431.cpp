/*
    시리얼 번호
    https://www.acmicpc.net/problem/1431
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    if(a.size()!=b.size()){
        return a.size()<b.size();
    } 
    int sum_a = 0, sum_b = 0;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0' && a[i]<='9'){
            sum_a+=a[i]-'0';
        }
        if(b[i]>='0' && b[i]<='9'){
            sum_b+=b[i]-'0';
        }
    }
    if(sum_a!=sum_b){
        return sum_a<sum_b;
    }
    return a.compare(b)<0;
}
int main(){
    int N;
    cin>>N;
    vector<string> serials(N);
    for(int i=0;i<N;i++){
        cin>>serials[i];
    }
    sort(serials.begin(), serials.end(), cmp);
    for(auto k: serials){
        cout<<k<<"\n";
    }
}