/*
    GPS
    https://programmers.co.kr/learn/courses/30/lessons/1837
*/
#include <bits/stdc++.h>

using namespace std;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    vector<list<int>> edges(n + 1);
    for (auto& edge : edge_list) {
        edges[edge[0]].push_back(edge[1]);
        edges[edge[1]].push_back(edge[0]);
    }

    for (size_t i = 1; i <= n; ++i)
        edges[i].push_back(i);

    vector<int> path(k);
    path[0] = gps_log[0];

    function<size_t(size_t)> visit = [&](size_t i)->size_t {
        size_t v = path[i - 1];

        if (i == k) {
            if (v == gps_log[k - 1])
                return 0;
            else
                return -1;
        }

        static pair<bool, size_t> visited[100][201] = {};
        size_t& min_error = visited[i][v].second;

        if (visited[i][v].first)
            return min_error;

        visited[i][v].first = true;
        min_error = -1;

        for (auto next : edges[v]) {
            path[i] = next;
            auto result = visit(i + 1);
            if (result != -1)
                min_error = min(min_error, (path[i] != gps_log[i]) + result);
        }
        
        return min_error;
    };

    return visit(1);
}