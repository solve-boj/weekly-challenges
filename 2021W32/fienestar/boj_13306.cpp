/*
    트리
    https://www.acmicpc.net/problem/13306
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

	vector<tuple<size_t,size_t,size_t>> quries(Q);
	for(auto& query:quries){
		auto& [x,b,c] = query;
		cin >> x >> b;

		if(x == 1)
			cin >> c;

		--b; --c;
	}

	list<size_t> old_parent;
	for(auto& query:quries)
		if(get<0>(query) == 0){
			auto second = get<1>(query);
			old_parent.push_front(parent[second]);
			parent[second] = second;
		}

	function<size_t(size_t)> root = [&](size_t n){
		if(parent[n] == n)
			return n;
		else
			return parent[n] = root(parent[n]);
	};

	list<bool> answer;
	auto old = old_parent.begin();
	for(size_t i=Q; i--;){
		auto& [x,b,c] = quries[i];

		if(x)
			answer.push_front(root(b) == root(c));
		else{
			auto a = root(b);
			auto b = root(*old++);

			parent[b] = a;
		}
	}

	for(auto c:answer)
		if(c)
			cout << "YES\n";
		else
			cout << "NO\n";
}