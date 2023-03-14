#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e16;

void solve() {
  ll n, m, s, t, c, d;  cin >> n >> m >> s >> t >> c >> d;  s--, t--;
  vector<array<ll, 2>> adj[n];
  vector<ll> mn(n, inf);
  for (int e = 0; e < m; ++e) {
    ll u, v, w;  cin >> u >> v >> w;  u--, v--;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    mn[u] = min(mn[u], w);
    mn[v] = min(mn[v], w);
  }

  int tot = (n + 1) * (n + 1);

  auto f = [&] (int u, int e) {
    return u * (n + 1) + e;
  };

  auto g = [&] (int uu) {
    return make_pair(uu / (n + 1), uu % (n + 1));
  };

  int lo = 1, hi = n;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    vector<ll> dis(tot, inf), vis(tot);
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<>> pq;
    int ss = f(s, mid);
    dis[ss] = 0;
    pq.push({0, ss});

    int ok = 0;
    while (!pq.empty()) {
      auto [p, uu] = pq.top();  pq.pop();
      if (vis[uu])  continue;
      vis[uu] = 1;

      auto [u, e] = g(uu);

      // u->anc:d, anc->u: d
      if (u != s) {
        int vv = f(u, mid);
        ll now = p + 2 * d;
        if (now <= c and dis[vv] > now) {
          dis[vv] = now;
          pq.push({dis[vv], vv});
        }
      }
      if (e == 0)  continue;

      if (u == t) {
        ok = 1;
        break;
      }

      for (auto [v, w]: adj[u]) {
        int vv = f(v, e - 1);
        ll now = p + w;
        if (now <= c and dis[vv] > now) {
          dis[vv] = now;
          pq.push({dis[vv], vv});
        }
      }

      // u->v: mn[u], v->u: d
      if (mn[u] < inf) {
        int vv = f(u, mid);
        ll now = p + mn[u] + d;
        if (now <= c and dis[vv] > now) {
          dis[vv] = now;
          pq.push({dis[vv], vv});
        }
      }
    }

    if (ok)  hi = mid - 1;
    else  lo = mid + 1;
  }

  if (lo > n) {
    cout << "Impossible\n";
  }
  else {
    cout << lo << "\n";
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
