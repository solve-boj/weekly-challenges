/*
    스카이라인
    https://www.acmicpc.net/problem/1933
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;

	using pii = pair<int, int>;
	vector<pii> v(N * 2);
	for (size_t i = 0; i != N; ++i) {
		int l, h, r;
		cin >> l >> h >> r;

		v[i << 1] = { l,h };
		v[i << 1 | 1] = { r,-h };
	}

	sort(v.begin(), v.end());
	map<int, size_t> m;
	auto execute = [&m](int h) {
		if (h > 0)++m[h];
		else if (!--m[-h])m.erase(-h);
	};

	auto it = v.begin();
	int y = 0;
	while (it != v.end()) {
		auto [x, h] = *it++;

		execute(h);

		while (it != v.end() && x == it->first) {
			auto [x, h] = *it++;
			execute(h);
		}

		int mh = 0;
		if (m.size())
			mh = m.rbegin()->first;

		if (y != mh) {
			cout << x << " " << mh << " ";
			y = mh;
		}
	}
}