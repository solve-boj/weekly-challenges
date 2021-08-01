/*
    무한 수열
    https://www.acmicpc.net/problem/1351
*/
#include <iostream>
#include <map>
using namespace std;

map<long long, long long> memo;

long long sol(long long i, long long n1, long long n2){
    if(memo.find(i) == memo.end()){ long long temp = sol(i/n1, n1, n2) + sol(i/n2, n1, n2); memo[i] = temp; }
    return memo[i];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, p, q;
    cin >> n >> p >> q;

    memo[0] = 1;
    cout << sol(n, p, q);

    return 0;
}
/*
    자료형 같은 걸로 어이없게 실수 내지 말 것...
    long long을 더하면 long long이 나오는데 그걸 int에 담으면 당연히..ㅋㅋ
*/