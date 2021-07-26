/*
    캠프가는 영식
    https://www.acmicpc.net/problem/1590
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N, T;
	cin >> N >> T;

	size_t answer = -1;
	while(N--){
		size_t begin, d, c;
		cin >> begin >> d >> c;

		if(T > begin + d*(c-1))
			continue;

		size_t i = 0;
		if(T >= begin)
			i = (T - begin + d - 1) / d;

		answer = min(answer, begin+d*i - T);
	}

	cout << (int)answer;
}