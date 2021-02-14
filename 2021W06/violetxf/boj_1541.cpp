/*
    잃어버린 괄호
    https://www.acmicpc.net/problem/1541
*/
#include <iostream>
#include <string>
using namespace std;
enum{
    NOOP,
    PLUS,
    MINUS
};
string input;
int cursor = 0;
string nextToken(){
    if(cursor>=input.size()) return "";
    if(input[cursor]=='-'||input[cursor]=='+'){
        ++cursor;
        return input.substr(cursor-1,1);
    }
        
    int end=cursor;
    while(input[end]>='0' && input[end]<='9' && end<input.size()){
        ++end;
    }
    int prevcursor = cursor;
    cursor = end;
    --end;

    return input.substr(prevcursor, end-prevcursor+1);
}

int main(){
    
    cin>>input;
    string token;
    int total = 0;
    int subsum = 0;
    int currentOp = NOOP;
    bool groupingMinus = false;
    while((token = nextToken()) != ""){
        //cout<<"proc"<<token<<"\n";
        if(groupingMinus){
            if(token=="-"){
                total-=subsum;
                subsum = 0;
            } else if(token!="+"){
                subsum+=stoi(token);
            }
        } else if(token=="-"){
            groupingMinus = true;
            //cout<<"grouping"<<"\n";
            continue;
        } else if(token!="+"){
            total+=stoi(token);
        }
    }
    total-=subsum;
    cout<<total;
}
