/*
    받아쓰기
    https://www.acmicpc.net/problem/20542
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t n, m;
	cin >> n >> m;

	string a, b;
	cin >> a >> b;

	auto match = [](char a, char b){
		if(a == b)
			return true;
		if(a == 'i' && (b == 'j' || b == 'l'))
			return true;
		if(a == 'v' && b == 'w')
			return true;
		return false;
	};

	function<ull(size_t,size_t)> distance = [&](size_t i, size_t j){
		static vector<vector<ull>> memo(n+1, vector<ull>(m+1, -1));

		if(i == n && j == m)
			return 0ull;

		auto& ret = memo[i][j];
		if(ret != -1)
			return ret;

		if(i != n && j != m)
			ret = min(ret, distance(i+1,j+1)+!match(a[i],b[j]));
		if(i != n)
			ret = min(ret, distance(i+1,j)+1);
		if(j != m)
			ret = min(ret, distance(i,j+1)+1);

		return ret;
	};

	cout << distance(0,0);
}