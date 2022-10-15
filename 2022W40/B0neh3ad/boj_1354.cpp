#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef __float128 F128;
const ll MOD = 1e9 + 7;
const int MAX = 50;
const int MAX_N = 10;

ll n, p, q, x, y;
map<ll, ll> cache;

ll solve(ll i) {
  if (i <= 0) {
    return 1;
  }

  if (cache.count(i)) {
    return cache[i];
  }

  return cache[i] = solve(i / p - x) + solve(i / q - y);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> p >> q >> x >> y;
  cout << solve(n);

  return 0;
}