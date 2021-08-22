/*
    스타 수열
    https://programmers.co.kr/learn/courses/30/lessons/70130
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int last[500000];
int maxlen[500000];

int solution(vector<int> a) {
    fill(last, last+a.size(), -1);
    int answer = -1;
    if (a.size() == 1) return 0;

    for(int i=0;i<a.size();i++) {
        if(i-1 == last[a[i]]) {
            if(i<a.size()-1 && a[i] != a[i+1]) {
                last[a[i]] = i+1;
                maxlen[a[i]] += 2;
            }
        }
        else {
            if(a[i] != a[i-1]) {
                last[a[i]] = i;
                maxlen[a[i]] += 2;
            }
            else if(i<a.size()-1 && a[i] != a[i+1]) {
                last[a[i]] = i+1;
                maxlen[a[i]] += 2;
            }
        }
    }
    
    for(int i=0;i<a.size();i++) {
        answer = max(answer, maxlen[i]);
    }

    return answer;
}


// keyword: DP
// 시간복잡도: O(N)
/*
idea: 
*/