/*
    석판 자르기
    https://www.acmicpc.net/problem/2447
*/

#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int board[20][20];
vector<pair<int, int>> impurities;
vector<pair<int, int>> crystals;
int N;

int f(int x, int xe, int y, int ye, int k) {
    //printf("<%d %d %d %d>\n", x, xe, y, ye);
    int res = 0;
    bool flag_h = true, flag_v = true;
    vector<pair<int,int>> ilist, clist;
    //printf("im\n");
    for(int i=0;i<impurities.size();i++) {
        if((x <= impurities[i].first) && (impurities[i].first < xe)
        && (y <= impurities[i].second) && (impurities[i].second < ye)) {
            //printf("%d %d\n", impurities[i].first, impurities[i].second);
            ilist.push_back(impurities[i]);
        }
    }
    //printf("cr\n");
    for(int i=0;i<crystals.size();i++) {
        if((x <= crystals[i].first) && (crystals[i].first < xe)
        && (y <= crystals[i].second) && (crystals[i].second < ye)) {
            //printf("%d %d\n", crystals[i].first, crystals[i].second);
            clist.push_back(crystals[i]);
        }
    }
    if((ilist.size() == 0) && (clist.size() == 1)) {
        //printf("<%d %d %d %d> %d. %d\n", x, xe, y, ye, 1, k);
        return 1;
    }
    else if(ilist.size() == 0) {
        //printf("<%d %d %d %d> %d. %d\n", x, xe, y, ye, 0, k);
        return 0;
    }
    if(clist.size() == 0) {
        //printf("<%d %d %d %d> %d. %d\n", x, xe, y, ye, 0, k);
        return 0;
    }
    for(auto i = ilist.begin();i != ilist.end();i++) {
        flag_h = (k != 1);
        flag_v = (k != 2);
        for(auto j = clist.begin();j != clist.end();j++) {
            if ((*i).first == (*j).first) {
                flag_h = false;
            }
            if ((*i).second == (*j).second) {
                flag_v = false;
            }
        }
        if (flag_h) {
            res += f(x, (*i).first, y, ye, 1) * f((*i).first + 1, xe, y, ye, 1);
        }
        if (flag_v) {
            res += f(x, xe, y, (*i).second, 2) * f(x, xe, (*i).second + 1, ye, 2);
            }
    }
    //printf("<%d %d %d %d> %d %d\n", x, xe, y, ye, res, k);
    return res;
}

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 1) {
                impurities.push_back(make_pair(i, j));
            }
            else if (board[i][j] == 2) {
                crystals.push_back(make_pair(i, j));
            }
        }
    }
    int res = f(0, N, 0, N, 0);
    printf("%d", res?res:-1);
}

// keyword: 분할 정복
// 시간복잡도: O(NC^2) (C는 결정체의 최대 개수)
/*
idea: 모든 불순물 위치에 대해 가로, 세로로 자르는 경우를 시도
잘린 석판 조각에서 똑같은 작업 시행(분할 정복), 단 이전과 같은 방향으로 자를 순 없음
*/