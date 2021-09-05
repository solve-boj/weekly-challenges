/*
    Suffix Array
    https://www.acmicpc.net/problem/9248
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	string str;
	cin >> str;

	const auto N = str.size();

	vector<size_t> group(N);

	size_t d;

	auto cmp = [&](size_t i, size_t j) {
		if(group[i] != group[j])
			return group[i] < group[j];

		i += d;
		j += d;

		if(i < N && j < N)
			return group[i] < group[j];
		else
			return i > j;
	};

	vector<size_t> sa(N);
	
	for(size_t i=0; i!=N; ++i) {
		sa[i] = i;
		group[i] = str[i];
	}

	vector<size_t> temp(N);
	for(d=1;;d<<=1){
		sort(sa.begin(), sa.end(), cmp);

		fill(temp.begin(), temp.end(), 0);

		for(size_t i=1; i!=N; ++i)
			temp[i] = temp[i-1] + cmp(sa[i-1], sa[i]);

		for(size_t i=0; i!=N; ++i)
			group[sa[i]] = temp[i];

		if(temp[N-1] == N-1)
			break;
	}

	vector<size_t> lcp(N-1);
	size_t k = 0;
	for(size_t i=0; i!=N; ++i) {
		if(group[i] == N-1)
			continue;
		for(size_t j=sa[group[i]+1]; str[i+k] == str[j+k]; ++k);

		lcp[group[i]] = k;
		if(k)--k;
	}

	for(auto& c:sa)
		cout << c+1 << " ";
	cout << "\nx ";

	for(auto& c:lcp)
		cout << c << " ";
}