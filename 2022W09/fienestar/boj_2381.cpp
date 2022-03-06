/*
    최대 거리
    https://www.acmicpc.net/problem/2381
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    size_t N;
    cin >> N;

    int sum_min = 2'000'000;
    int sum_max = -2'000'000;
    int sub_min = 2'000'000;
    int sub_max = -2'000'000;

#define update(o, v) (o##_min = min(o##_min, v)), o##_max = max(o##_max, v)

    while(N--){
        int x,y;
        cin >> x >> y;

        update(sum, x+y);
        update(sub, x-y);
    }

#undef update

    cout << max(sum_max - sum_min, sub_max - sub_min);
}