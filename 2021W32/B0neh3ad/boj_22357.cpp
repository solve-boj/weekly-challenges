/*
    경품 추첨
    https://www.acmicpc.net/problem/22357
*/
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int isNotPrime[3001];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n;
    cin >> k >> n;

    int ans[k][n], cha = 2001;

    isNotPrime[0] = isNotPrime[1] = -1;
    for(int i=2; i*i<3000; ++i){
        for(int j=i*i; j<=3000; j+=i){
            isNotPrime[j] = 1; // 1: 소수 아님 / 0: 소수임
        }
    }

    for(int cnt = 0; cnt<k; ++cnt){
        while(isNotPrime[cha]){ ++cha; }
        ans[cnt][0] = 1;
        cout << ans[cnt][0] << " ";
        for(int j=1; j<n; ++j){
            ans[cnt][j] = ans[cnt][j-1] + cha;
            cout << ans[cnt][j] << " ";
        }
        cout << "\n";
        ++cha;
    }
    
    return 0;
}

/*
    어떤 점에서 아이디어에 문제가 있었는가?
    K=5, N=10을 예로 들면 10X6 = 12X5 같은 경우 고려 안 함.
    답은 n보다 큰 소수...

    오늘의 교훈: aXb != cXd 처럼 뭔가 곱했을 때 같지 않아야 하는 경우는 소수를 고려해보자.
*/