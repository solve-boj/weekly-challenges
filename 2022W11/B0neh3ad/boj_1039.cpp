#include <bits/stdc++.h>
using namespace std;

int n, k;
int digit;
bool dp[1000000][11];

int arrayToInt(int arr[], int len){
    int res = 0;
    for(int i=0; i<len; ++i){
        res *= 10;
        res += arr[i];
    }
    return res;
}

void sol(){
    queue<int> q;

    dp[n][0] = true;
    q.push(n);
    for(int x=1; x<=k; ++x){
        int qsize = q.size();
        // cout << "x: " << x << "\n";
        for(int t=0; t<qsize; ++t){
            int curr = q.front();
            q.pop();

            int d[digit];
            for(int i=digit-1; i>=0; --i, curr /= 10){
                d[i] = curr % 10;
            }

            for(int i=0; i<digit-1; ++i){
                for(int j=i+1; j<digit; ++j){
                    if(i == 0 && d[j] == 0){ continue; }
                    swap(d[i], d[j]);
                    int next = arrayToInt(d, digit);
                    if(!dp[next][x]){
                        dp[next][x] = true;
                        // cout << next << '\n';
                        q.push(next);
                    }
                    swap(d[i], d[j]);
                }
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    if(n == 1000000){
        cout << 1000000;
        return 0;
    }

    digit = 1;
    for(int i=10; i<=1000000; i *= 10){
        if(n < i){ break; }
        ++digit;
    }

    int d[digit];
    for(int i=digit-1, temp=n; i>=0; --i, temp /= 10){
        d[i] = temp % 10;
    }

    sol();

    bool flag = false;
    for(int i=1000000-1; i>0; --i){
        if(dp[i][k]){
            flag = true;
            cout << i;
            break;
        }
    }
    
    if(!flag){
        cout << -1;
    }
    
    return 0;
}