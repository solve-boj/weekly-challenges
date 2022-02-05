/*
    AC
    https://www.acmicpc.net/problem/5430
*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int T, n;
string str;
deque<int> dq;
bool dir, error;

int main() {
    int temp;
    scanf("%d", &T);
    for(int i=0;i<T;i++) {
        dir = true;
        error = false;
        cin >> str;
        scanf("%d\n", &n);
        scanf("[");
        for(int j=0;j<n;j++) {
            scanf("%d", &temp);
            dq.push_back(temp);
            if(j<n-1) scanf(",");
        }
        scanf("]");
        for(char c: str) {
            if (c=='R') {
                dir = !dir;
            }
            else if (c=='D') {
                if(dq.empty()) {
                    error = true;
                    break;
                }
                if(dir) dq.pop_front();
                else dq.pop_back();
            }
        }

        if(error) {
            printf("error\n");
            continue;
        }
        if(dir) {
            printf("[");
            for(int j=0;j<dq.size();j++) {
                printf("%d", dq[j]);
                if(j<dq.size()-1) printf(",");
            }
            printf("]\n");
        }
        else {
            auto it = dq.rbegin();
            printf("[");
            for(int j=0;j<dq.size();j++) {
                printf("%d", dq[dq.size()-1-j]);
                if(j<dq.size()-1) printf(",");
            }
            printf("]\n");
        }
        dq.clear();
    }
}