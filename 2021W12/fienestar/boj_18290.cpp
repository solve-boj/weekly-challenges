/*
    NM과 K (1)
    https://www.acmicpc.net/problem/18290
*/
#include <bits/stdc++.h>

using namespace std;

bool is_adjacent(size_t a, size_t b, size_t N)
{
    size_t i = a / N;
    size_t j = a % N;
    size_t x = b / N;
    size_t y = b % N;

    int dx[] = { 1,-1,0,0 };
    int dy[] = { 0,0,1,-1 };

    for (size_t k = 0; k != 4; ++k)
        if (dx[k] + i == x && dy[k] + j == y) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> v(N, vector<int>(M));

    for (auto& c : v)
        for (auto& k : c)
            cin >> k;

    size_t end = N * M;
    int result = -40000;
    vector<size_t> selected(K);

    auto has_adjacent = [&]()
    {
        for (size_t i = 0; i != K; ++i)
            for (size_t j = i + 1; j != K; ++j)
                if (is_adjacent(selected[i], selected[j], M)) return true;
        return false;
    };

    function<void(size_t, size_t)> find = [&](size_t i, size_t begin) {
        if (i == K) {
            if (has_adjacent())return;
            int sum = 0;
            for (size_t j = 0; j != K; ++j)
                sum += v[selected[j] / M][selected[j] % M];
            result = max(result, sum);
            return;
        }

        for (size_t j = begin; j < end; ++j) {
            selected[i] = j;
            find(i + 1, j + 1);
        }
        return;
    };
    find(0, 0);
    cout << result;
}