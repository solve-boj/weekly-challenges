/*
    N과 M (2)
    https://www.acmicpc.net/problem/15650
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;
vector<int> a;
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
            v.push_back(a[i]);
            f(v, used);
            used[i] = false;
            v.pop_back();
        }
    }
}

int main() {
    int t;
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++) {
        scanf("%d", &t);
        a.push_back(t);
        sort(a.begin(), a.end());
    }
    f(v, used);
}