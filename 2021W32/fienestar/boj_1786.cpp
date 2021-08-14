/*
    찾기
    https://www.acmicpc.net/problem/1786
*/
#include <bits/stdc++.h>

using namespace std;

vector<size_t> make_pi(const string& P)
{
	vector<size_t> pi(P.size());
	size_t j = 0;

	for(size_t i=1; i!=P.size(); ++i){
		while(j && P[i] != P[j])
			j = pi[j-1];

		if(P[i] == P[j])
			pi[i] = ++j;
	}

	return pi;
	
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	string T, P;
	getline(cin, T);
	getline(cin, P);

	auto pi = make_pi(P);
	size_t j = 0;
	list<size_t> matched;
	for(size_t i=0; i!=T.size(); ++i){
		while(j && T[i] != P[j])
			j = pi[j-1];

		if(T[i] != P[j])
			continue;

		if(j + 1 == P.size()){
			matched.push_back(i - P.size() + 1);
			j = pi[j];
		}else
			++j;
	}

	cout << matched.size() << "\n";
	for(auto pos:matched)
		cout << pos+1 << " ";
}