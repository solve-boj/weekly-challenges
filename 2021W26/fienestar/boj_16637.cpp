/*
    괄호 추가하기
    https://www.acmicpc.net/problem/16637
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    size_t N;
    cin >> N;

    string exp;
    cin >> exp;

    auto eval = [](ll lhs, char op, ll rhs)->optional<ll> {
        switch (op) {
        case '+':
            return lhs + rhs;
        case '-':
            return lhs - rhs;
        case '*':
            return lhs * rhs;
        case '/':
            if (rhs == 0)
                return {};
            return lhs / rhs;
        default:
            return {};
        }
    };

    stack<pair<ll, char>> s; // lhs op ?
    s.emplace(0, '+');

    ll M = -2147483648;
    function<void(size_t)> find = [&](size_t i) {
        auto [s_lhs, s_op] = s.top();
        ll lhs = exp[i++] - '0';

        size_t max_op_in = 1;

        while (i != N) {
            char op = exp[i++];
            if (auto new_top = eval(s_lhs, s_op, lhs)) {
                s.emplace(new_top.value(), op);
                find(i);
                s.pop();
            }

            if (!max_op_in--)
                return;

            ll rhs = exp[i++] - '0';

            if (auto new_lhs = eval(lhs, op, rhs))
                lhs = new_lhs.value();
            else
                return;
        }

        if (auto result = eval(s_lhs, s_op, lhs))
            M = max(M, result.value());
    };

    find(0);

    cout << M;
}