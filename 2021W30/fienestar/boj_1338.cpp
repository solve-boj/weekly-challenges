/*
    알 수 없는 번호
    https://www.acmicpc.net/problem/1338
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	ll begin, end, x, y;
	cin >> begin >> end >> x >> y;
	x = abs(x);

	if(begin > end)swap(begin, end);

	ll answer = begin+((y-begin)%x+x)%x;

	if(y >= x || y < 0 || answer + x <= end || answer > end)
		cout << "Unknwon Number";
	else
        cout << answer;
}