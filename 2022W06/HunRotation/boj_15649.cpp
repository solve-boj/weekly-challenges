/*
    N과 M (1)
    https://www.acmicpc.net/problem/15649
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N, M;
vector<int> v;
vector<bool> used(8, false);

void f(vector<int> v, vector<bool> used) {
    if(v.size() == M) {
        for(int i:v) {
            printf("%d ", i);
        }
        printf("\n");
        return;
    }
    for(int i=0;i<N;i++) {
        if(!used[i]) {
            used[i] = true;
            v.push_back(i+1);
            f(v, used);
            used[i] = false;
            v.pop_back();
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    f(v, used);
}