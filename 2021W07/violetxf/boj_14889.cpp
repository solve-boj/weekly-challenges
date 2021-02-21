/*
    스타트와 링크
    https://www.acmicpc.net/problem/14889
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> map(21, vector<int>(21,0));
int N;
int minimum = 2147483647;
int sum(vector<int> sel){
    int res = 0;
    for(int i=0;i<sel.size();i++){
        for(int k=0;k<sel.size();k++){
            res+=map[sel[i]][sel[k]];
        }
    }
    return res;
}
void diff(vector<int>& sel, int next){
    if(sel.size()==N/2){
        vector<int> other;
        int temp = 0;
        for(int i=0;i<N;i++){
            if(sel[temp]==i){
                temp++;
                continue;
            }
            other.push_back(i);
        }
        minimum = min(minimum, abs(sum(sel)-sum(other)));
        return;
    }
    for(int i=next;i<N;i++){
        sel.push_back(i);
        diff(sel, i+1);
        sel.pop_back();
    }
}
int main(){
    vector<int>sel;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int k=0;k<N;k++){
            cin>>map[i][k];
        }
    }
    diff(sel,0);
    cout<<minimum;

}