/*
    외계인의 기타 연주
    https://www.acmicpc.net/problem/2841
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, P;
int n, p;
int moves = 0;
vector<stack<int>> strings(6);

int main() {
    cin >> N >> P;
    for(int i=0;i<N;i++) {
        cin >> n >> p;
        while(!strings[n-1].empty() && (strings[n-1].top() > p)) {
            strings[n-1].pop();
            ++moves;
        }
        if(strings[n-1].empty() || strings[n-1].top() < p) {
            strings[n-1].push(p);
            ++moves;
        }
    }
    cout << moves;
}