#include <bits/stdc++.h>
using namespace std;

int getNext(int num, int op){
    int d[4], temp = num;
    for(int i=3; i>=0; --i){
        d[i] = temp % 10;
        temp /= 10;
    }

    int res = 0;
    switch(op){
        case 0:
        res = 2*num % 10000;
        break;

        case 1:
        res = (num+9999) % 10000;
        break;

        case 2:
        for(int i=1; i<5; ++i){
            res *= 10;
            res += d[i%4];
        }
        break;

        case 3:
        for(int i=3; i<7; ++i){
            res *= 10;
            res += d[i%4];
        }
        break;
    }
    // cout << res << "\n";
    return res;
}

void bfs(int num, int goal){
    string ans[10000];
    string mode[4] = {"D", "S", "L", "R"};

    fill(ans, ans + 10000, " ");

    queue<int> q;

    q.push(num);
    ans[num] = "";

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(int i=0; i<4; ++i){
            int next = getNext(curr, i);
            if(ans[next] == " "){
                ans[next] = ans[curr] + mode[i];
                if(next == goal){
                    cout << ans[goal] << "\n";
                    return;
                }
                q.push(next);
            }
        }
    }
}

int main(void){
    int t;
    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;

        bfs(a, b);
    }
    return 0;
}