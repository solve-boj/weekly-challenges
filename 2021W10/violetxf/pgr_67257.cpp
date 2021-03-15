/*
    수식 최대화
    https://programmers.co.kr/learn/courses/30/lessons/67257
*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define NUMBER false
#define OPERATOR true
long long answer;
struct Token{
    string content;
};
vector<Token> tokens;
string operators[3] = {"-", "+", "*"};
bool used[3];
void bf(vector<string> &priority){
    // cout<<"called";
    // for(auto k :priority){
    //     cout<<k<<"\n";
    // }
    if(priority.size()==3){
        // cout<<"reached";
        //calculate
        vector<Token> temp_tokens;
        temp_tokens.resize(tokens.size());
        copy(tokens.begin(), tokens.end(), temp_tokens.begin());
        for(string op: priority){
            // cout<<"op:"+op<<"\n";
            
            for(int i=0;i<temp_tokens.size();i++){
                if(temp_tokens[i].content==op){
                    long long left = stoll(temp_tokens[i-1].content);
                    long long right = stoll(temp_tokens[i+1].content);
                    long long calc;
                    if(op=="*"){
                        calc = left*right;
                    } else if(op=="+"){
                        calc = left+right;
                    } else {
                        calc = left-right;
                    }
                    temp_tokens[i-1].content = to_string(calc);
                    
                    temp_tokens.erase(temp_tokens.begin()+i);
                    temp_tokens.erase(temp_tokens.begin()+i);
                    // for(Token tok: temp_tokens){
                    //     //cout<<tok.content;
                    // }
                    // cout<<"\n";
                    i--;
                }
            }
        }
        //cout<<temp_tokens.size()<<"\n\n";
        for(Token tok: temp_tokens){
            cout<<tok.content<<"\n";
        }
        long long result = abs(stoll(temp_tokens[0].content));
        answer = max(answer, result);
        //cout<<"ans"<<answer<<"\n";
    } else {
        for(int i=0;i<3;i++){
            if(used[i])continue;
            used[i] = true;
            priority.push_back(operators[i]);
            bf(priority);
            used[i] = false;
            priority.pop_back();
        }
    }
}
long long solution(string expression) {
    answer = 0;
    tokens.empty();
    string tok_str;
    int cursor = 0;
    bool was_number = true;
    used[0]=used[1]=used[2]=false;
    while(cursor<expression.size()){
        
        bool is_number = isdigit(expression[cursor]);
        if(is_number!=was_number){
            //new token
            Token tok;
            tok.content = tok_str;
            tokens.push_back(tok);
            tok_str="";
        }
        was_number = is_number;
        tok_str+=expression[cursor];
        ++cursor;
    }
    Token tok;
    tok.content = tok_str;
    tokens.push_back(tok);
    vector<string> temp;
    bf(temp);

    return answer;
}
int main(){
    cout<<solution("100-200*300-500+20");
}