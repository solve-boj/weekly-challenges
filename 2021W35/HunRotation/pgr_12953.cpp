/*
    모음 사전
    https://programmers.co.kr/learn/courses/30/lessons/12953
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b==0) return a;
    return gcd(b, a%b);
}

int solution(vector<int> arr) {
    int answer = arr[0];
    for(int i=1;i<arr.size();i++) {
        answer = answer*arr[i]/gcd(answer,arr[i]);
    }

    return answer;
}

// keyword: 최대공약수
// 시간복잡도: O(N)
/*
idea: 두 수의 곱 = gcd*lcm
*/