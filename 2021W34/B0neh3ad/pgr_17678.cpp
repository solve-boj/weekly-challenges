/*
    셔틀버스
    https://programmers.co.kr/learn/courses/30/lessons/17678
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> data_to_min(vector<string>& data){
    vector<int> res;
    for(auto time: data)
        res.push_back(stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2)));

    return res;
}

string min_to_data(int min){
    string res;
    if(min / 60 < 10){ res += "0"; }
    res += to_string(min / 60);
    res += ":";
    if(min % 60 < 10){ res += "0"; }
    res += to_string(min % 60);

    return res;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> new_timetable = data_to_min(timetable);
    sort(new_timetable.begin(), new_timetable.end());

    int last_pass = 0; // 마지막 탑승한 승객의 인덱스. 아무도 탑승하지 않은 경우에도 0.
    int temp_ans = 0;
    int bus_num = 0, personnel = 0;
    while(bus_num < n && last_pass < new_timetable.size()){
        int bus_time = 540 + bus_num*t;
        personnel = 0;
        while(new_timetable[last_pass] <= bus_time && personnel < m){
            ++last_pass;
            ++personnel;
            // 다 태웠으면 나가기
            if(last_pass == new_timetable.size()){ break; }
        }
        ++bus_num;
    }
    if(last_pass){ --last_pass; }
    // 막차까지 만원이 아니라면 막차에 태우기
    if(personnel < m){ temp_ans = 540 + (n-1)*t; }
    // 마지막 승객보다 1분 빨리 오기
    else{ temp_ans = new_timetable[last_pass] - 1;}

    return min_to_data(temp_ans);
}
/*
    size_t 사용시 overflow 항상 조심!
    만원 여부에 대한 판단, 마지막 승객 인덱싱 등
    자잘한 부분을 유의해야 한다.
*/