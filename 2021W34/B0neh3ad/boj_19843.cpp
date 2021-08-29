/*
    [미포함] 수면 패턴
    https://www.acmicpc.net/problem/19843
*/
#include <bits/stdc++.h>

using namespace std;

int main(void){
    string week_arr[5] = {"Mon", "Tue", "Wed", "Thu", "Fri"};
    map<string, int> week;
    for(int i=0; i<5; ++i){ week[week_arr[i]] = i*24; }
    
    int T, N;
    cin >> T >> N;

    int answer = 0;
    for(int i=0; i<N; ++i){
        string D1, D2;
        int H1, H2;
        cin >> D1 >> H1 >> D2 >> H2;
        answer += (week[D2] + H2) - (week[D1] + H1);
    }

    answer = T - answer;
    if(answer <= 0){ cout << 0; }
    else if(answer > 48){ cout << -1; }
    else{ cout << answer; }

    return 0;
}