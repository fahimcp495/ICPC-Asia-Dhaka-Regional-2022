#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define dbg(a)  cerr << #a << ": " << a << "\n"

const int N = 20, Q = 202;

int n, q;
array<int, 2> op[Q];
ll dp[1 << N];

ll fn (int mask) {
  ll &ret = dp[mask];
  if (ret != -1)  return ret;
  int x = mask;
  for (int e = 0; e < q; ++e) {
    auto [i, j] = op[e];
    if (!(x & (1 << i)) and (x & (1 << j))) {
      x ^= (1 << i);
      x ^= (1 << j);
    }
  }

  for (int i = 0; i + 1 < n; ++i) {
    if (!(x & (1 << i)) and (x & (1 << (i + 1)))) {
      return ret = 0;
    }
  }
  if (mask == (1 << n) - 1)  return ret = 1;
  ret = 0;
  for (int i = 0; i < n; ++i) {
    if (!(mask & (1 << i))) {
      ret += fn(mask | (1 << i));
    }
  }
  return ret;
}

void solve() {
  cin >> n >> q;
  for (int e = 0; e < q; ++e) {
    auto &[x, y] = op[e];
    cin >> x >> y;  x--, y--;
  }

  for (int mask = 0; mask < (1 << n); ++mask) {
    dp[mask] = -1;
  }

  cout << fn(0) << "\n";
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int tc;  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    solve();
  }
}
