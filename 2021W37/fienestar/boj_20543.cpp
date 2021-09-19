/*
    폭탄 던지는 태영이
    https://www.acmicpc.net/problem/20543
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t n, m;
	cin >> n >> m;

	size_t hm = m >> 1;

	vector<vector<ll>> v(n, vector<ll>(n));
	for(auto& line:v)
		for(auto& dot:line)
			cin >> dot;

	vector<vector<ll>> ans(n, vector<ll>(n));
	for(size_t j=hm; j+hm!=n; ++j){
		ll sum = 0;
		for(size_t i=hm; i+hm!=n; ++i){
			sum += ans[i][j] = -v[i-hm][j-hm] - sum;
			if(i >= m)
				sum -= ans[i-m+1][j];
		}
	}

	for(size_t i=hm; i+hm!=n; ++i){
		ll sum = 0;
		for(size_t j=hm; j+hm!=n; ++j){
			sum += ans[i][j] -= sum;
			if(j >= m)
				sum -= ans[i][j-m+1];
		}
	}

	for(auto& line:ans){
		for(auto dot:line)
			cout << dot << " ";
		cout << "\n";
	}
}