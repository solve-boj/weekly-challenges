/*
    창고 다각형
    https://www.acmicpc.net/problem/2304
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, L, H, tot = 0;
int maxposL, maxposR;
int maxHL = 0, maxHR = 0;
vector<pair<int, int>> pillars;

int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> L >> H;
        pillars.push_back({L, H});
    }
    sort(pillars.begin(), pillars.end());
    maxposL = (*pillars.begin()).first;
    maxposR = (*pillars.rbegin()).first;

    for(auto it = pillars.begin(); it != pillars.end(); it++) {
        if((*it).second > maxHL) {
            tot += maxHL * ((*it).first - maxposL);
            maxposL = (*it).first;
            maxHL = (*it).second;
        }
    }

    for(auto it = pillars.rbegin(); it != pillars.rend(); it++) {
        if((*it).second > maxHR) {
            tot += maxHR * (-(*it).first + maxposR);
            maxposR = (*it).first;
            maxHR = (*it).second;
        }
    }

    tot += maxHL * (maxposR - maxposL + 1);

    cout << tot;
}