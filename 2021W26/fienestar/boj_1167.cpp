/*
    트리의 지름
    https://www.acmicpc.net/problem/1167
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t V;
	cin >> V;

	vector<list<pair<size_t, size_t>>> E(V);
	while(V--){
		size_t v;
		cin >> v;
		size_t to, cost;
		while((cin >> to) && to != -1){
			cin >> cost;
			E[v-1].emplace_back(to-1, cost);
			E[to-1].emplace_back(v-1, cost);
		}
	}

	bool visited[100000];
	function<pair<size_t,size_t>(size_t)> longest= [&](size_t v){
		visited[v] = true;

		pair<size_t, size_t> p = {-1,0};
		for(auto edge:E[v])
			if(!visited[edge.first]){
				auto result = longest(edge.first);
				if(result.second + edge.second > p.second){
					p.first = result.first;
					p.second = result.second + edge.second;
				}
			}

		if(p.first == -1)
			p.first = v;

		return p;
	};

	auto visit = [&](size_t v){
		memset(visited, 0, sizeof(visited));
		return longest(v);
	};

	cout << visit(visit(0).first).second;
}