/*
    노트북의 주인을 찾아서
    https://www.acmicpc.net/problem/1298
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N, M;
	cin >> N >> M;

	vector<list<size_t>> adj(N);
	while(M--){
		size_t a, b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
	}

	vector<size_t> own(N, -1);
	bool visited[100];
	function<bool(size_t)> can = [&](size_t v){
		visited[v] = true;
		for(auto b:adj[v])
			if(own[b] == -1 || !visited[own[b]] && can(own[b])){
				own[b] = v;
				return true;
			}
		return false;
	};

	size_t count = 0;
	for(size_t i=0; i!=N; ++i){
		memset(visited, 0, 100);
		count += can(i);
	}

	cout << count;
}