/*
    좋은 친구
    https://www.acmicpc.net/problem/3078
*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<queue<int>> q(19);

string str;
int N, K;
long long pairs = 0;
int temp;

int main() {
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        cin >> str;
        q[str.size()-2].push(i);
        while(!q.empty() && q[str.size()-2].front() < i-K) {
            q[str.size()-2].pop();
        }
        pairs += q[str.size()-2].size()-1;
    }
    
    cout << pairs;
}