/*
    봉화대
    https://www.acmicpc.net/problem/22880
*/
#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int N;
    vector<pair<int, int> > incline; // first: idx, second: height

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int temp;
    cin >> temp;
    incline.push_back({0, temp});
    for(int i=1; i<N; ++i){
        cin >> temp;
        if(incline.back().second < temp){ incline.push_back({i, temp}); }
    }

    long long answer = 1;
    for(int i=1; i<incline.size(); ++i){
        answer *= incline[i].first - incline[i-1].first + 1;
        answer %= 1000000007;
    }

    cout << answer;
    return 0;
}
/*
    이게 왜 골드??
*/