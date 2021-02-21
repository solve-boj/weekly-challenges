/*
    괄호 변환
    https://programmers.co.kr/learn/courses/30/lessons/60058
*/
#include <string>
#include <vector>
#include <iostream>
#define MODE_BALANCED 0
#define MODE_CLOSED 1
using namespace std;

bool check(string str, int mode){
    int open = 0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            open++;
        } else if(str[i]==')'){
            open--;
        }
        if(mode == MODE_CLOSED && open<0)return false;
    }
    return open==0;
}
string solve(string p){
    if(p=="")return "";
    int divider;//divider is inclusive
    string u,v;
    for(int i=1;i<p.size();i++){ 
        u = p.substr(0, i+1);
        if(check(u, MODE_BALANCED)){
            divider = i;
            break;
        }
        
    }
    v = p.substr(divider+1, p.size()-divider);
    if(check(u, MODE_CLOSED)){
        return u+solve(v);
    } else {
        string temp = "(";
        temp+=solve(v)+")";
        for(int i=1;i<u.size()-1;i++){
            if(u[i]=='(')temp+=")"; else temp+="(";
        }
        return temp;
    }
}
string solution(string p) {
    if(check(p, MODE_CLOSED)) return p;
    return solve(p);
}
// int main(){
//     cout<<solution("(()())()")<<"\n";
//     cout<<solution(")(")<<"\n";
//     cout<<solution("()))((()");
// }