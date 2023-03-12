#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define dbg(a)  cerr << #a << ": " << a << "\n"

void solve() {
  double k;  cin >> k;

  double r = (k * k - 1) / (4 - k * k);
  r = sqrtl(r);

  cout << fixed << setprecision(4) << r << "\n";
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int tc;  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    solve();
  }
}
