/*
    사다리
    https://www.acmicpc.net/problem/3061
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> vec;
        for(int i=0;i<n;i++){
            int input;
            cin>>input;
            vec.push_back(input);
        }
        int count = 0;
        for(int i=0;i<n;i++){
            for(int k=i+1;k<n;k++){
                if(vec[i]>vec[k]){
                    int temp = vec[i];
                    vec[i] = vec[k];
                    vec[k] = temp;
                    count++;
                }
            }
        }
        cout<<count<<"\n";
    }
}