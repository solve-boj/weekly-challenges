#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

bool cmp(const pii& lhs, const pii& rhs){ return lhs.second > rhs.second; }

int main(void){
    map<string, int> team;
    long double per[4][4];

    memset(per, 0, sizeof(per));

    string inp;
    for(int i=0; i<4; ++i){
        cin >> inp;
        team[inp] = i;
    }

    string a, b;
    for(int i=0; i<6; ++i){
        long double w, d, l;
        cin >> a >> b >> w >> d >> l;

        per[team[a]][team[b]] = w;
        per[team[b]][team[a]] = l;
    }

    int match[6][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
    long double res_per[4] = {0, };
    for(int res=0; res<729; ++res){
        long double curr_per = 1;
        pair<int, int> score[4];
        for(int i=0; i<4; ++i){
            score[i].first = i;
            score[i].second = 0;
        }

        for(int i=0, temp=res; i<6; temp/=3, ++i){
            int curr_res = temp%3;
            int lhs = match[i][0], rhs = match[i][1];

            switch(curr_res){
                case 0: // win
                curr_per *= per[lhs][rhs];
                score[lhs].second += 3;
                break;

                case 1: // draw
                curr_per *= 1 - (per[lhs][rhs] + per[rhs][lhs]);
                score[lhs].second += 1;
                score[rhs].second += 1;
                break;
                
                case 2: // lose
                curr_per *= per[rhs][lhs];
                score[rhs].second += 3;
                break;
            }
        }
        sort(score, score+4, cmp);

        if(score[1].second > score[2].second){
            res_per[score[0].first] += curr_per;
            res_per[score[1].first] += curr_per;
        }
        else if(score[0].second > score[1].second){ 
            res_per[score[0].first] += curr_per;
            if(score[2].second > score[3].second){ // 2, 3등 동일
                res_per[score[1].first] += curr_per/2;
                res_per[score[2].first] += curr_per/2;
            }
            else{ // 2, 3, 4등 동일
                res_per[score[1].first] += curr_per/3;
                res_per[score[2].first] += curr_per/3;
                res_per[score[3].first] += curr_per/3;
            }
        }
        else if(score[2].second > score[3].second){ // 1, 2, 3등 동일
            res_per[score[0].first] += curr_per*2/3;
            res_per[score[1].first] += curr_per*2/3;
            res_per[score[2].first] += curr_per*2/3;
        }
        else{ // 1, 2, 3, 4등 동일
            res_per[score[0].first] += curr_per*2/4;
            res_per[score[1].first] += curr_per*2/4;
            res_per[score[2].first] += curr_per*2/4;
            res_per[score[3].first] += curr_per*2/4;
        }
    }

    for(int i=0; i<4; ++i){
        cout << res_per[i] << '\n';
    }
    return 0;
}