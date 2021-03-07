/*
    스택 수열
    https://www.acmicpc.net/problem/1874
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    bool no = false;
    vector<int> stack;
    vector<int> arr;
    vector<char> op;
    int n;
    cin>>n;
    stack.push_back(1);
    op.push_back('+');
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        arr.push_back(k);
    }
    int cur = 0;
    int num = 2;
    while(cur<n){
        if(stack.back()<arr[cur]){
            stack.push_back(num++);
            op.push_back('+');
        } else if(stack.back()==arr[cur]){
            stack.pop_back();
            op.push_back('-');
            cur++;
        } else {
            stack.pop_back();
            op.push_back('-');
        }
        if(num>n+1){
            no = true;
            break;
        }
    }
    
    if(!no){
        for(char c: op){
            cout<<c<<"\n";
        }
    } else {
        cout<<"NO";
    }
}