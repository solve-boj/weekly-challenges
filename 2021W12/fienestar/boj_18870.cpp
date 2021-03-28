/*
    좌표 압축
    https://www.acmicpc.net/problem/18870
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	size_t N;
	cin >> N;

	vector<pair<int,size_t>> v(N);
	for(size_t i=0; i!=N; ++i){
		cin >> v[i].first; v[i].second = i;
	}
	sort(v.begin(),v.end());

	vector<size_t> result(N);
	result[v[0].second] = 0;
	for(size_t i=1; i!=N; ++i)
		result[v[i].second] = result[v[i-1].second] + (v[i-1].first != v[i].first);

	for(auto v:result)
		cout << v << " ";
}