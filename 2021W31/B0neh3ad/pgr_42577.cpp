/*
    전화번호 목록
    https://programmers.co.kr/learn/courses/30/lessons/42577
*/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> numbers;

    for(string& number: phone_book)
        numbers.insert({number, 1});

    for(string number: phone_book){
        string prefix = "";

        prefix += number[0];
        for(int i=0; i < number.size()-1; prefix += number[++i])
            if(numbers.find(prefix) != numbers.end()){ answer = false; break; }

        if(!answer){ break; }
    }

    return answer;
}
/*
    해시테이블(unordered_map) 써도 되고..
    더 최적화 하려면 트라이 쓰면 될 듯?


    ㅋㅋ 정렬 쓰면 풀리네
    앞이 0이 아닌 경우로 강제된다면 sorting 후 to_string(stoi(phone_book[i])+1)<phone_book[i+1] 로 판단 가능
*/