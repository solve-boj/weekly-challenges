/*
    Strongly Connected Component
    https://www.acmicpc.net/problem/2150
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t V, E;
	cin >> V >> E;

	vector<list<size_t>> edges(V);
	vector<list<size_t>> reversed_edges(V);
	while(E--){
		size_t A, B;
		cin >> A >> B;
		--A; --B;

		edges[A].push_back(B);
		reversed_edges[B].push_back(A);
	}

	static bool in_scc[10000];
	bool* current_visited;
	vector<list<size_t>>* current_edges;
	function<void(size_t)> visit = [&](size_t v){
		current_visited[v] = true;

		for(auto next:(*current_edges)[v])
			if(!current_visited[next] && !in_scc[next])
				visit(next);
	};

	list<list<size_t>> scc_list;
	static bool visited[2][10000];

	for(size_t i=0; i!=V; ++i)
		if(!in_scc[i]){
			memset(visited[0], 0, sizeof(visited[0]));
			current_visited = visited[0];
			current_edges = &reversed_edges;
			visit(i);

			memset(visited[1], 0, sizeof(visited[1]));
			current_visited = visited[1];
			current_edges = &edges;
			visit(i);

			list<size_t> scc;
			scc.push_back(i);
			for(size_t j=i+1; j!=V; ++j)
				if(visited[0][j] && visited[1][j]){
					in_scc[j] = true;
					scc.push_back(j);
				}

			scc_list.emplace_back(move(scc));
		}

	cout << scc_list.size() << "\n";
	for(auto& scc:scc_list){
		for(auto& v:scc)
			cout << v+1 << " ";
		cout << "-1\n";
	}
}