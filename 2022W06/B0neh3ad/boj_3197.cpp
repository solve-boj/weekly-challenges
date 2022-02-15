#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int r, c;
char lake[1500][1500];
int dy[] = {0, -1, 0, 1}, dx[] = {1, 0, -1, 0};

bool isInside(int y, int x){ return (y>=0 && y<r && x>=0 && x<c); }

bool markMovable(pii s1, pii s2){
    queue<pii> q;
    q.push(s1);
    
    while(!q.empty()){
        pii curr = q.front();
        q.pop();
        for(int i=0; i<4; ++i){
            pii next = pii(curr.first + dy[i], curr.second + dx[i]);
            if(next.first >= 0 && next.first < r && next.second >= 0 && next.second < c){
                if(lake[next.first][next.second] == '.'){
                    lake[next.first][next.second] = '1';
                    q.push(next);
                }
            }
        }
    }

    q = queue<pii>();
    q.push(s2);

    while(!q.empty()){
        pii curr = q.front();
        q.pop();
        for(int i=0; i<4; ++i){
            pii next = pii(curr.first + dy[i], curr.second + dx[i]);
            if(isInside(next.first, next.second)){
                if(lake[next.first][next.second] == '.'){
                    lake[next.first][next.second] = '2';
                    q.push(next);
                }
                else if(lake[next.first][next.second] == '1'){
                    return false;
                }
            }
        }
    }

    return true;
}

int melt(){
    queue<pii> q;
    
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            if(lake[i][j] == 'X'){
                bool ad_flag = false;
                for(int k=0; k<4; ++k){
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(ny >= 0 && ny < r && nx >= 0 && nx < c){
                        if(lake[ny][nx] == '.' || lake[ny][nx] == '1' || lake[ny][nx] == '2'){
                            ad_flag = true;
                            break;
                        }
                    }
                }
                if(ad_flag){
                    lake[i][j] = 'C'; // close ice
                    q.push(pii(i, j));
                }
            }
        }
    }

    int day = 1;
    while(!q.empty()){
        int qsize = q.size();
        for(int x=0; x<qsize; ++x){
            pii curr = q.front();
            q.pop();

            bool rable1 = false, rable2 = false, urable = false;
            for(int i=0; i<4; ++i){
                pii next = pii(curr.first + dy[i], curr.second + dx[i]);
                if(isInside(next.first, next.second)){
                    switch(lake[next.first][next.second]){
                        case 'X':
                        lake[next.first][next.second] = 'C';
                        q.push(next);
                        break;

                        case '.':
                        lake[curr.first][curr.second] = '.';
                        urable = true;
                        break;

                        case '1':
                        lake[curr.first][curr.second] = '1';
                        rable1 = true;
                        break;

                        case '2':
                        lake[curr.first][curr.second] = '2';
                        rable2 = true;
                        break;
                    }
                }
            }
            if(rable1 & rable2){
                return day;
            }
            else if(rable1 & urable | rable2 & urable){
                char mark = rable1 ? '1' : '2';
                queue<pii> wq;
                lake[curr.first][curr.second] = mark;
                wq.push(curr);

                while(!wq.empty()){
                    pii wcurr = wq.front();
                    wq.pop();

                    for(int i=0; i<4; ++i){
                        pii wnext = pii(wcurr.first + dy[i], wcurr.second + dx[i]);
                        if(isInside(wnext.first, wnext.second)){
                            if(lake[wnext.first][wnext.second] == '.'){
                                lake[wnext.first][wnext.second] = mark;
                                wq.push(wnext);
                            }
                            else if(lake[wnext.first][wnext.second] == '1' || lake[wnext.first][wnext.second] == '2'){
                                if(lake[wnext.first][wnext.second] != mark){
                                    return day;
                                }
                            }
                        }
                    }
                }
            }
        }
        ++day;
    }

    return day;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;

    pii swan[2];
    int cnt = 0;
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            cin >> lake[i][j];
            if(lake[i][j] == 'L'){
                swan[cnt++] = pii(i, j);
                lake[i][j] = '0' + cnt;
            }
        }
    }

    if(!markMovable(swan[0], swan[1])){
        cout << "0";
        return 0;
    }

    cout << melt();
    return 0;
}