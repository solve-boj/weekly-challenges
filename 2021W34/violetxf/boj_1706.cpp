#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int r, c;
    cin>>r>>c;
    string table[21];
    for(int i=0;i<r;i++){
        cin>>table[i];
    }
    vector<string> tokens;
    //left to right
    for(int i=0;i<r;i++){
        bool blocked = false;
        string token = "";
        for(int k=0;k<c;k++){
            if(table[i][k] == '#'){
                blocked = true;
            } else {
                if(blocked){ // new token begins
                    if(token.size()>=2)
                        tokens.push_back(token);
                    token = table[i][k];
                } else {
                    token += table[i][k];
                }
                blocked = false;
            }
        }
        if(token.size()>=2){
            tokens.push_back(token);
        }
    }
    for(int k=0;k<c;k++){
        bool blocked = false;
        string token = "";
        for(int i=0;i<r;i++){
            if(table[i][k] == '#'){
                blocked = true;
            } else {
                if(blocked){ // new token begins
                    if(token.size()>=2)
                        tokens.push_back(token);
                    token = table[i][k];
                } else {
                    token += table[i][k];
                }
                blocked = false;
            }
        }
        if(token.size()>=2){
            tokens.push_back(token);
        }
    }
    sort(tokens.begin(), tokens.end());
    cout<<tokens[0];
}