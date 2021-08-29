/*
    비슷한 단어
    https://www.acmicpc.net/problem/1411
*/
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    
    vector<string> vec(N, "");
    for(int i=0;i<N;i++){
        string input;
        cin>>input;
        map<char, int> m;
        int id = 0;
        for(int k=0;k<input.size();k++){
            if(m.find(input[k]) == m.end()){
                m[input[k]] = id++;
            }
            vec[i]+=to_string(m[input[k]]);
        }

    }
    int answer = 0;
    for(int i=0;i<N;i++){
        for(int k=i+1;k<N;k++){
            if(vec[i] == vec[k])answer++;
        }
    }
    cout<<answer;

}