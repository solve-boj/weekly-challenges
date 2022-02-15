/*
    N과 M (3)
    https://www.acmicpc.net/problem/15651
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void f(vector<int> v) {
    if(v.size() == M) {
        for(int i:v) {
            printf("%d ", i);
        }
        printf("\n");
        return;
    }
    for(int i=(v.empty())?0:v[v.size()-1]-1;i<N;i++) {
        v.push_back(i+1);
        f(v);
        v.pop_back();
    }
}

int main() {
    scanf("%d %d", &N, &M);
    f(v);
}