#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define dbg(a)  cerr << #a << ": " << a << "\n"

const int N = 55;

ll p2[N];

ll f (ll k, ll n) {
  if (n == 0) {
    if (k == 1)  return 1;
    if (k == 2)  return 2;
    if (k == 3)  return 2;
    if (k == 4)  return 4;
    assert(false);
  }
  if (k <= p2[n + 1])  return f(k, n - 1);
  else  return 2 * f(k - p2[n + 1], n - 1);
}

void solve() {
  ll k, n;  cin >> k >> n;
  if (k > p2[n + 2]) {
    cout << "-1\n";
    return ;
  }
  cout << f(k, n) << "\n";
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  p2[0] = 1;
  for (int i = 1; i < N; ++i) {
    p2[i] = 2 * p2[i - 1];
  }

  int tc;  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    cout << "Case " << t << ": ";
    solve();
  }
}
