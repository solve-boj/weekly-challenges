/*
    임진왜란
    https://www.acmicpc.net/problem/3077
*/
#include <map>
#include <vector>
#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    map<string, int> answer;
    vector<string> names;
    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        answer[name] = i;
        names.push_back(name);
    }
    map<string, int> attempt;
    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        attempt[name] = i;
    }
    int score = 0;
    for(int i=0;i<n;i++){
        for(int k=i+1;k<n;k++){
            string name = names[i];
            string name2 = names[k];
            if(attempt[name]<attempt[name2]){
                score++;
            }
        }
    }
    cout<<score<<'/'<<n*(n-1)/2<<"\n";
}