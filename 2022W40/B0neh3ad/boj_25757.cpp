#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef __float128 F128;
const int MAX = 987654321;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  char kind;
  cin >> kind;

  int ans = 0;
  map<string, bool> m;
  for (int i = 0; i < n; ++i) {
    string inp;
    cin >> inp;
    ans += !(m.count(inp));
    m[inp] = 1;
  }

  switch (kind) {
  case 'Y':
    cout << ans;
    break;

  case 'F':
    cout << ans / 2;
    break;

  case 'O':
    cout << ans / 3;
    break;
  }

  return 0;
}