/*
    그래프의 싱크
    https://www.acmicpc.net/problem/6543
*/
#include <bits/stdc++.h>

using namespace std;

void solve(size_t n, size_t m)
{
	vector<list<size_t>> E[2];

	E[0].resize(n); E[1].resize(n);

	while(m--){
		size_t v, w;
		cin >> v >> w;
		--v; --w;

		E[0][v].push_back(w);
		E[1][w].push_back(v);
	}

	static bool has_out[2];
	static bool visited[2][5000];
	static size_t in_scc[5000];

	memset(in_scc, 0, sizeof(in_scc));

	size_t mod;
	function<void(size_t)> visit = [&](size_t v){
		visited[mod][v] = true;

		for(auto w:E[mod][v])
			if(!visited[mod][w]){
				if(in_scc[w])
					has_out[mod] = true;
				else
					visit(w);
			}
	};

	for(size_t i=0; i!=n; ++i)
		if(!in_scc[i]){
			has_out[0] = false;
			memset(visited, 0, sizeof(visited));

			for(mod = 0; mod!=2; ++mod)
				visit(i);

			in_scc[i] = 1;

			if(has_out[0])
				in_scc[i] = 2;
			else
				for(size_t j=i+1; j!=n; ++j)
					if(visited[0][j] && !visited[1][j]){
						in_scc[i] = 2;
						break;
					}

			for(size_t j=i+1; j!=n; ++j)
				if(visited[0][j] && visited[1][j])
					in_scc[j] = in_scc[i];
		}

	for(size_t i=0; i!=n; ++i)
		if(in_scc[i] == 1)
			cout << i+1 << " ";

	cout << "\n";
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t n, m;
	while(cin >> n >> m)
		solve(n, m);
}