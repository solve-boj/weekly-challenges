/*
    친구 네트워크
    https://www.acmicpc.net/problem/4195
*/
#include <bits/stdc++.h>

using namespace std;

void solve()
{
	size_t F;
	cin >> F;

	vector<size_t> parent(F*2+1);
	vector<size_t> rank(F*2+1);
	for(size_t i=0; i!=parent.size(); ++i) {
		parent[i] = i;
		rank[i] = 1;
	}

	function<size_t(size_t)> root = [&](size_t i) {
		if(parent[i] == i)
			return i;
		else
			return parent[i] = root(parent[i]);
	};

	auto merge = [&](size_t a, size_t b) {
		a = root(a);
		b = root(b);

		if(a == b)
			return rank[a];

		if(rank[a] < rank[b])
			swap(a,b);

		rank[a] += rank[b];
		parent[b] = a;

		return rank[a];
	};

	map<string, size_t> idx;
	string a, b;
	size_t i = 0;
	while(F--){
		cin >> a >> b;
		auto& ai = idx[a];
		auto& bi = idx[b];
		if(!ai)ai = ++i;
		if(!bi)bi = ++i;

		cout << merge(ai, bi) << "\n";;
	}
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t T;
	cin >> T;

	while(T--)
		solve();
}