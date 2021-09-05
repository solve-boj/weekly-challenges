/*
    가장 긴 문자열
    https://www.acmicpc.net/problem/3033
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;

	string str;
	str.reserve(N);

	cin >> str;

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

	vector<size_t> lcp(N);
	size_t k = 0;
	for(size_t i=0; i!=N; ++i) {
		if(group[i] == N-1)
			continue;

		for(size_t j=sa[group[i]+1]; str[i+k] == str[j+k]; ++k);

		lcp[group[i]] = k;
		if(k)--k;
	}

	cout << *max_element(lcp.begin(), lcp.end());
}