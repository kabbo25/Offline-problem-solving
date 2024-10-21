#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector dp(n, (int64_t)0);
  vector v(n, 0);
  for (auto &x : v)
    cin >> x;
  dp[0] = max<int64_t>(dp[0], v[0]);
  for (int i(1); i < n; ++i) {
    if (i - 2 >= 0) {
      dp[i] = max(dp[i - 2] + v[i], dp[i - 1]);
    } else
      dp[i] = max<int64_t>(v[i], dp[i - 1]);
  }
  cout << dp.back() << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i(0); i < t; ++i)
    solve();
  return 0;
}