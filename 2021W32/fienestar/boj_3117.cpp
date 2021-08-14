/*
    YouTube
    https://www.acmicpc.net/problem/3117
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N, K, M;
	cin >> N >> K >> M;
	--M;

	vector<size_t> st(N);
	for(auto& v:st){
		cin >> v;
		--v;
	}

	vector<size_t> rs[30];
	rs[0].resize(K);
	for(auto& r:rs[0]){
		cin >> r;
		--r;
	}

	for(size_t i=1; i!=30; ++i){
		rs[i].resize(K);
		for(size_t j=0; j!=K; ++j)
			rs[i][j] = rs[i-1][rs[i-1][j]];
	}

	for(auto v:st){
		for(size_t i=30; i--;)
			if(M & (1<<i))
				v = rs[i][v];

		cout << v+1 << " ";
	}
}