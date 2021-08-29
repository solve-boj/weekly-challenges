/*
    여우 신탁
    https://www.acmicpc.net/problem/19847
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    scanf("%d", &N);

    vector<int> arr;

    int x;
    scanf("%d", &x);
    arr.push_back(x);
    vector<int> table(x, 1);

    for(int i=1; i<N; ++i){
        scanf("%d", &x);
        if(arr.back() > x)
            arr.push_back(x);
    }

    for(int i=1; i<arr.size(); ++i)
        for(int j=arr[i-1]-1; j>=arr[i]; --j)
            table[j%arr[i]] += table[j];

    double answer;
    for(int i=0; i<arr.back(); ++i)
        answer += i*table[i];
    
    answer /= double(arr.front());

    printf("%.10lf", answer);
    return 0;
}
/*
    long double에서는 비교 연산자가 잘 안 돌아가나?
*/