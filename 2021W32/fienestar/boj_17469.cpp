/*
    트리의 색깔과 쿼리
    https://www.acmicpc.net/problem/17469
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N, Q;
	cin >> N >> Q;
	Q += N-1;

	vector<size_t> parent(N);
	parent[0] = 0;
	for(size_t i=1; i!=N; ++i){
		cin >> parent[i];
		--parent[i];
	}

	vector<set<size_t>> colors(N);
	for(auto& s:colors){
		size_t color;
		cin >> color;
		s.insert(color);
	}

	vector<pair<size_t, size_t>> quries(Q);
	for(auto& query:quries){
		cin >> query.first >> query.second;
		--query.second;
	}

	list<size_t> old_parent;
	for(auto& query:quries)
		if(query.first == 1){
			old_parent.push_front(parent[query.second]);
			parent[query.second] = query.second;
		}

	function<size_t(size_t)> root = [&](size_t n){
		if(parent[n] == n)
			return n;
		else
			return parent[n] = root(parent[n]);
	};

	for(size_t i=1; i!=N; ++i)
		colors[root(i)].merge(colors[i]);

	list<size_t> answer;
	auto old = old_parent.begin();
	for(size_t i=Q; i--;)
		if(quries[i].first == 2)
			answer.push_front(colors[root(quries[i].second)].size());
		else{
			auto a = root(quries[i].second);
			auto b = root(*old++);

			if(colors[a].size() < colors[b].size())
				swap(a,b);

			colors[a].merge(colors[b]);
			parent[b] = a;
		}

	for(auto c:answer)
		cout << c << "\n";
}