/*
    오픈채팅방
    https://programmers.co.kr/learn/courses/30/lessons/42888
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string str, char del){
    vector<string> answer;
    stringstream ss(str);
    string temp;

    while(getline(ss, temp, del))
        answer.push_back(temp);
    
    return answer;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> info;

    for(vector<string>::iterator it=record.begin(); it!=record.end(); ++it){
        vector<string> temp = split(*it, ' ');
        switch(temp[0][0]){
            case 'E': // 입장
            if(info.find(temp[1]) == info.end())
                info.insert(make_pair<string, string>(temp[1].data(), temp[2].data()));
            else
                info[temp[1].data()] = temp[2].data();
                break;
            case 'C': // 변경
                info[temp[1].data()] = temp[2].data();
                break;
        }
    }

    for(vector<string>::iterator it=record.begin(); it!=record.end(); ++it){
        vector<string> temp = split(*it, ' ');
        switch(temp[0][0]){
            case 'E':
                answer.push_back(info[temp[1].data()]+u8"님이 들어왔습니다.");
                break;
            case 'L':
                answer.push_back(info[temp[1].data()]+u8"님이 나갔습니다.");
                break;
        }
    }
    return answer;
}

int main(void){
    
    return 0;
}