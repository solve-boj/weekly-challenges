/*
    리유나는 세일러복을 좋아해
    https://www.acmicpc.net/problem/18138
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N, M;
	cin >> N >> M;

	vector<size_t> tshirts(N);
	for(auto& w:tshirts)
		cin >> w;

	sort(tshirts.begin(), tshirts.end());

	vector<size_t> sailor_collar(M);
	for(auto& w:sailor_collar){
		cin >> w;
		w *= 4;
	}

	sort(sailor_collar.begin(), sailor_collar.end());

	vector<size_t> own(M, -1);
	bool visited[200];
	function<bool(size_t)> can = [&](size_t i){
		visited[i] = true;
		size_t w = tshirts[i];

		size_t j;
		j = lower_bound(sailor_collar.begin(), sailor_collar.end(), w * 2) - sailor_collar.begin();
		for(;j != M && sailor_collar[j] <=  w * 3; ++j)
			if(own[j]==-1 || !visited[own[j]] && can(own[j])){
				own[j] = i;
				return true;
			}

		j = lower_bound(sailor_collar.begin() + j, sailor_collar.end(), w * 4) - sailor_collar.begin();
		for(;j != M && sailor_collar[j] <=  w * 5; ++j)
			if(own[j]==-1 || !visited[own[j]] && can(own[j])){
				own[j] = i;
				return true;
			}

		return false;
	};

	size_t count = 0;
	for(size_t i=0; i!=N; ++i){
		memset(visited, 0, sizeof(visited));
		count += can(i);
	}

	cout << count;
}
