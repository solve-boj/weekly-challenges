/*
    다음수 구하기
    https://www.acmicpc.net/problem/2697
*/
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    
    vector<char> vec;
    while(T--){
        string a;
        cin>>a;
        int hold_position = -1;
        if(a.size()==1){
            cout<<"BIGGEST\n";
            continue;
        }
        for(int i=a.size();i>0;i--){
            char right = a[i];
            char left = a[i-1];
            if(right>left){
                hold_position = i-1;
                break;
            }
        }
        if(hold_position==-1){
            cout<<"BIGGEST\n";
            continue;
        }
        char change_num = '9'+1;
        int change_position = -1;
        for(int i=a.size();i>hold_position;i--){
            if(a[hold_position]<a[i]){
                if(a[i]<change_num){
                    change_num = a[i];
                    change_position = i;
                }
            }
        }
        a[change_position] = a[hold_position];
        a[hold_position] = change_num;
        
        for(int i=hold_position+1; i<a.size();i++){
            vec.push_back(a[i]);
        }
        sort(vec.begin(), vec.end());
        for(int i=0;i<=hold_position; i++){
            cout<<a[i];
        }
        for(int i=0;i<vec.size();i++){
            cout<<vec[i];
        }
        cout<<"\n";

        vec.clear();
    }
}