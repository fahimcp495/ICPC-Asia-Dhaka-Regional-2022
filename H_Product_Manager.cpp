#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define dbg(a)  cerr << #a << ": " << a << "\n"

const int N = 21;

ll fact[N];

void solve() {
  ll n, k;  cin >> n >> k;
  vector<int> t(n);
  for (auto &ti: t) {
    cin >> ti;
  }

  cout << fact[n] << "\n";
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = fact[i - 1] * i;
  }

  int tc;  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    cout << "Case " << t << ": ";
    solve();
  }
}
