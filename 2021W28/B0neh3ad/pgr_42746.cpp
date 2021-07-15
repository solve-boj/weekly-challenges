/*
    가장 큰 수
    https://programmers.co.kr/learn/courses/30/lessons/42746
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(const int &lhs, const int &rhs){
    string lhs_s = to_string(lhs);
    string rhs_s = to_string(rhs);

    return (lhs_s + rhs_s) > (rhs_s + lhs_s);
}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), cmp);
    for(vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++){
        answer.append(to_string(*it));
    }

    answer = (answer[0] == '0') ? "0" : answer;
    return answer;
}

/*
    새로 배운 것
    int, float -> string으로 바꿔주는 to_string 함수
    c++에서도 + 연산자로 string concatenating 할 수 있다
    아래처럼 쓰면 array를 vector로 쉽게 바꿀 수 있다
    int arr = {1, 2, 3};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
*/