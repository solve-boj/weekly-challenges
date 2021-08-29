/*
    도로 네트워크
    https://www.acmicpc.net/source/32670146
*/
#include <bits/stdc++.h>

using namespace std;

struct max_min_t
{
	size_t M;
	size_t m;

	max_min_t operator&(max_min_t oth)
	{
		return {
			max(M, oth.M),
			min(m, oth.m)
		};
	}

	max_min_t& operator&=(max_min_t oth)
	{
		return *this = *this & oth;
	}
};

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	using edge_t = pair<size_t, size_t>;
	vector<list<edge_t>> E(N);
	for(size_t i=1; i!=N; ++i) {
		size_t A, B, C;
		cin >> A >> B >> C;
		--A; --B;

		E[A].emplace_back(B, C);
		E[B].emplace_back(A, C);
	}

	vector<size_t> dept(N);
	size_t dept_i = 0;
	vector<vector<size_t>> parent(18, vector<size_t>(N));
	vector<vector<max_min_t>> max_min(18, vector<max_min_t>(N));
	function<void(size_t)> dfs = [&](size_t i) {
		dept[i] = ++dept_i;
		for(auto& [next, cost]:E[i])
			if(!dept[next]) {
				parent[0][next] = i;
				max_min[0][next] = { cost, cost };
				dfs(next);
			}
		--dept_i;
	};

	dfs(0);

	for(size_t i=1; i!=18; ++i)
		for(size_t j=0; j!=N; ++j) {
			parent[i][j] = parent[i-1][parent[i-1][j]];
			max_min[i][j] = max_min[i-1][j] & max_min[i-1][parent[i-1][j]];
		}

	size_t K;
	cin >> K;
	while(K--) {
		size_t D, E;
		cin >> D >> E;
		--D; --E;

		if(dept[D] < dept[E])
			swap(D, E);

		size_t diff = dept[D] - dept[E];
		max_min_t answer = { 0, -1u };
		for(size_t i=0; diff; ++i) {
			if(diff&1){
				answer &= max_min[i][D];
				D = parent[i][D];
			}
			diff >>= 1;
		}

		if(D != E) {
			for(size_t i=18; i--;)
				if(parent[i][D] != parent[i][E]) {
					answer &= max_min[i][D] & max_min[i][E];
					D = parent[i][D];
					E = parent[i][E];
				}

			answer &= max_min[0][D] & max_min[0][E];
		}

		cout << answer.m << " " << answer.M << "\n";
	}
}