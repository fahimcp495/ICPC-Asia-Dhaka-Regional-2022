#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define dbg(a)  cerr << #a << ": " << a << "\n"

void solve() {
  ll lb, sb, db;  cin >> lb >> sb >> db;
  ll lc, sc, dc;  cin >> lc >> sc >> dc;
  ll lt, st;  cin >> lt >> st;

  if (sb >= st or sc >= st) {
    cout << "-1\n";
    return ;
  }

  if (db > dc) {
    swap(lb, lc);
    swap(sb, sc);
    swap(db, dc);
  }

  cout << fixed << setprecision(4);

  ll gap = dc - lc - db;
  if (sb == sc) {
    if (gap < lt) {
      cout << "-1\n";
    }
    else {
      double t = 1.0 * (dc + lt) / (st - sc);
      cout << t << "\n";
    }
  }
  else if (sb < sc) {
    double t1 = 1.0 * (db + lt) / (st - sb);
    double t2 = 1.0 * (lt - gap) / (sc - sb);
    double t = max(t1, t2);
    t += (dc - db + t * (sc - sb)) / (st - sc);
    cout << t << "\n";
  }
  else {
    double t = 1.0 * (db + lt) / (st - sb);
    gap = (gap - t * (sb - sc));
    if (gap >= lt) {
      t += (dc - db + t * (sc - sb)) / (st - sc);
      cout << t << "\n";
    }
    else {
      double t1 = 1.0 * (dc + lt) / (st - sc);
      double t2 = 1.0 * (dc - db + lb + lt) / (sb - sc);
      double t = max(t1, t2);
      t += (-dc + db + t * (sb - sc)) / (st - sb);
      cout << t << "\n";
    }
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    cout << "Case " << t << ": ";
    solve();
  }
}
