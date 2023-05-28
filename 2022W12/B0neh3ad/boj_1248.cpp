#include <bits/stdc++.h>
using namespace std;

int n;
int sign[10][10];
bool ans_flag;

void sol(int idx, int seq[], int psum[]){
    if(ans_flag){
        return;
    }

    if(idx == n){
        for(int i=0; i<n; ++i){
            cout << seq[i] << ' ';
        }
        ans_flag = true;
    }

    if(!sign[idx][idx]){
        seq[idx] = 0;
        psum[idx+1] = psum[idx];
        sol(idx+1, seq, psum);
    }

    for(int a=1; a<=10; ++a){
        int val = a*sign[idx][idx];

        bool flag = true;

        for(int i=0; i<=idx; ++i){
            switch(sign[i][idx]){
                case -1:
                if(psum[idx] - psum[i] + val >= 0){
                    flag = false;
                    break;
                }
                break;

                case 1:
                if(psum[idx] - psum[i] + val <= 0){
                    flag = false;
                    break;
                }
                break;

                case 0:
                if(psum[idx] - psum[i] + val != 0){
                    flag = false;
                    break;
                }
                break;
            }
        }

        if(flag){
            seq[idx] = val;
            psum[idx+1] = psum[idx] + val;
            sol(idx+1, seq, psum);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    char inp;
    for(int i=0; i<n; ++i){
        for(int j=i; j<n; ++j){
            cin >> inp;
            switch(inp){
                case '+':
                sign[i][j] = 1;
                break;

                case '-':
                sign[i][j] = -1;
                break;

                case '0':
                sign[i][j] = 0;
                break;
            }
        }
    }

    int seq[n], psum[n+1];
    psum[0] = 0;

    sol(0, seq, psum);

    return 0;
}