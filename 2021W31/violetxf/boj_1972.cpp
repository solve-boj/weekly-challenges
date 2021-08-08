/*
    놀라운 문자열
    https://www.acmicpc.net/problem/1972
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
   
    while(true){
        bool notsp = false;
        
        string line;
        cin>>line;
        if(line=="*"){
            break;
        }
        for(int i=1;i<=line.size()-1;i++){
            map<string, bool> m;
            for(int k=0;k+i<line.size();k++){
                string dpair = line.substr(k,1)+line.substr(k+i,1);
                if(m.find(dpair) != m.end()){
                    cout<<line<<" is NOT surprising.\n";
                    notsp = true;
                    break;
                }
                m.insert({dpair, true});
            }
            if(notsp)break;
        }
        if(!notsp)cout<<line<<" is surprising.\n";
    }
}