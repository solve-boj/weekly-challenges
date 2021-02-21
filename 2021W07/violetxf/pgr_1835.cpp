
/*
    단체사진 찍기
    https://programmers.co.kr/learn/courses/30/lessons/1835
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
string friends = "ACFJMNRT";
int answer = 0;
vector<string>conditions;
vector<bool> used;
bool check(vector<char>order){
    for(string cond: conditions){
        char f1 = cond[0];
        char f2 = cond[2];
        char op = cond[3];
        int num = cond[4]-'0';
        int f1idx = 0;
        int f2idx = 0;
        for(int i=0;i<order.size();i++){
            if(order[i] == f1){
                f1idx = i;
            }
            if(order[i] == f2){
                f2idx = i;
            }
        }
        int dist = abs(f1idx-f2idx)-1;
        switch(op){
            case '>':
                if(dist<=num)return false;
            break;
            case '<':
                if(dist>=num)return false;
            break;
            case '=':
                if(dist!=num)return false;
            break;
        }
    }
    return true;
}
void solve(vector<char>&order, int next){
    if(order.size()==8){
        if(check(order)){
            answer++;
        }
        return;
    }
    for(int i=0;i<8;i++){
        if(!used[i]){
            used[i] = true;
            order.push_back(friends[i]);
            solve(order, i+1);
            order.pop_back();
            used[i] = false;
        }
    }

}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    answer = 0;
    conditions = data;
    used = vector<bool>(8, false);
    vector<char> temp;
    solve(temp, 0);
    return answer;
}
int main(){
    cout<<solution(2, {"N~F=0","R~T>2"});
}