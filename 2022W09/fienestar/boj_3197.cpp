/*
    백조의 호수
    https://www.acmicpc.net/problem/3197
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t R, C;
	cin >> R >> C;

	using pos_t = pair<size_t, size_t>;
	vector<vector<pos_t>> mark(R, vector<pos_t>(C, { -1, -1 }));

	function<pos_t(pos_t)> root = [&](pos_t pos) {
		auto& parent = mark[pos.first][pos.second];
		if(parent.first == -1)return pos;
		return parent = root(parent);
	};

	auto merge = [&](pos_t a, pos_t b) {
		a = root(a);
		b = root(b);

		if(a != b)
			mark[b.first][b.second] = a;
	};

	int di[] = { 1,-1,0,0 };
	int dj[] = { 0,0,1,-1 };

	pos_t l[2];
	size_t l_i = 0;

	vector<string> v(R);
	queue<pos_t> q;
	q.emplace(-1, -1);

	vector<vector<uint8_t>> visited(R, vector<uint8_t>(C));

	for(size_t i = 0; i != R; ++i){
		cin >> v[i];
		for(size_t j = 0; j != C; ++j)
			if(v[i][j] != 'X'){
				q.emplace(i, j);
				visited[i][j] = true;

				if(v[i][j] == 'L')
					l[l_i++] = { i,j };

				for(size_t k = 0; k != 4; ++k){
					auto [mi, mj] = pos_t{ i + di[k], j + dj[k] };
					if(mi < R && mj < C && v[mi][mj] != 'X')
						merge({ i,j }, { mi,mj });
				}
			}
	}

	auto check = [&](pos_t from, size_t i, size_t j) {
		merge(from, { i,j });
		if(!visited[i][j]){
			q.emplace(i, j);
			visited[i][j] = true;
		}
	};

	size_t time = 0;
	while(true){
		auto [i, j] = q.front();
		q.pop();

		if(i == -1){
			if(root(l[0]) == root(l[1])){
				cout << time;
				return 0;
			}

			++time;
			q.emplace(-1, -1);
			continue;
		}

		for(size_t k = 0; k != 4; ++k){
			auto [mi, mj] = pos_t{ i + di[k], j + dj[k] };

			if(mi >= R || mj >= C)continue;

			check({ i,j }, mi, mj);

			if(v[mi][mj] == 'X'){
				v[mi][mj] = '.';

				for(size_t o = 0; o != 4; ++o){
					auto [oi, oj] = pos_t{ mi + di[o], mj + dj[o] };
					if(oi >= R || oj >= C)continue;
					if(v[oi][oj] != 'X')
						check({ mi,mj }, oi, oj);
				}
			}
		}
	}
}