/*
    [1차] 추석 트래픽
    https://programmers.co.kr/learn/courses/30/lessons/17676
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll operator""_ms(ull n) { return n; }
constexpr ll operator""_s(ull n) { return n * 1000_ms; }
constexpr ll operator""_m(ull n) { return n * 60_s; }
constexpr ll operator""_h(ull n) { return n * 60_m; }

template <class T>
T parse_number(string num)
{
    T n;
    istringstream(num) >> n;
    return n;
}

pair<ll,ll> parse_line(string line)
{
    ll result = 0;
    result += parse_number<ll>(line.substr(11,13)) * 1_h;
    result += parse_number<ll>(line.substr(14,16)) * 1_m;
    result += parse_number<ll>(line.substr(17,19)) * 1_s;
    result += parse_number<ll>(line.substr(20,22)) * 1_ms;
    
    string diff_str = line.substr(23);
    ll diff = 0;
    size_t processed = 0;
    for(size_t i=0; i!=diff_str.size(); ++i)
        if(isdigit(diff_str[i])){
            diff = diff*10 + diff_str[i] - '0';
            ++processed;
        }
    
    for(size_t i=processed; i!=4; ++i)
        diff *= 10;
    
    return {result - diff + 1, result + 999};
}

int solution(vector<string> lines) {
    vector<pair<ll,ll>> times;
    for(auto& line:lines){
        auto p = parse_line(line);
        cout << "=====\n" << line << "\n";
        cout << p.first << "\n";
        cout << p.second << "\n";
        times.push_back({p.first,-1});
        times.push_back({p.second,1});
    }
    
    sort(times.begin(),times.end());
    
    ll answer = 0;
    ll now = 0;
    cout << "=====\n";
    for(auto& time:times){
        now -= time.second;
        answer = max(answer, now);
        cout << time.first << ": " << now << "\n";
    }
    
    return answer;
}