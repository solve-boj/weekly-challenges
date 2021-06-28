/*
    책 나눠주기
    https://www.acmicpc.net/problem/9576
*/

#include <bits/stdc++.h>

using namespace std;

void solve()
{
	size_t N, M;
	cin >> N >> M;

	assert(M <= 1000);

	vector<pair<size_t, size_t>> adj(M);
	for(auto& v:adj)
		cin >> v.first >> v.second;

	vector<size_t> own(N, -1);
	bool visited[1000];
	function<bool(size_t)> can = [&](size_t v){
		visited[v] = true;
		for(size_t i=adj[v].first-1; i!=adj[v].second; ++i)
			if(own[i] == -1 || !visited[own[i]] && can(own[i])){
				own[i] = v;
				return true;
			}
		return false;
	};

	size_t count = 0;
	for(size_t i=0; i!=M; ++i){
		memset(visited, 0, 1000);
		count += can(i);
	}

	cout << count << "\n";
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t T;
	cin >> T;

	while(T--)
		solve();
}