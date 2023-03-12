#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = (1ll << 61);
const int N = 1003;

ll dp[N][3*N+64];

void solve() {
  int n;  cin >> n;
  vector<ll> a(n);
  for (auto &ai: a) {
    cin >> ai;
  }

  int m = 3 * n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      dp[i][j] = inf;
    }
  }
  dp[0][0] = a[0];

  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ll x = dp[i][j], y = a[i + 1], cnt = 0;
      if (x == inf)  continue;
      if (x < y)  dp[i+1][j] = min(dp[i+1][j], y);

      for (ll v = (1ll << 59); v > 0; v >>= 1) {
        if (!(x & v)) {
          if (y & v) dp[i+1][j+cnt] = min(dp[i+1][j+cnt], y);
          else dp[i+1][j+cnt+1] = min(dp[i+1][j+cnt+1], y | v);
        }
        else if (!(y & v))  y |= v, cnt++;
      }

    }
  }

  for (int j = 0; j < m; ++j) {
    if (dp[n - 1][j] != inf) {
      cout << j << "\n";
      return ;
    }
  }

}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int tc;  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    cout << "Case " << t << ": ";
    solve();
  }
}
