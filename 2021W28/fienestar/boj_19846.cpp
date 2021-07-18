/*
    신기한 연산
    https://www.acmicpc.net/problem/19846
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N, M;
	cin >> N >> M;

	while(M--)
		cout << char('a'+(M>>1)%N);
}