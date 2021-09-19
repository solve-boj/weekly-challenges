/*
    큰 수 만들기
    https://www.acmicpc.net/problem/16496
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;

	vector<string> v(N);
	bool is_all_zero = true;
	for(auto& c:v){
		cin >> c;
		is_all_zero = is_all_zero && c == "0";
	}

	if(is_all_zero){
		cout << "0";
		return 0;
	}

	sort(v.begin(), v.end(), [](auto& a, auto& b) {
		return a+b > b+a;
	});

	for(auto& c:v)
		cout << c;
}