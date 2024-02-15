// time-limit: 1000
// problem-url: https://lightoj.com/problem/commandos
#include <bits/stdc++.h>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v)
    os << sep << x, sep = ", ";
  return os << '}';
}
clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#ifndef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
void solve() {
  int n, m;
  cin >> n >> m;
  vector adj(n, vector(0, 0));
  for (int i(0); i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  vector dis_from_source(n, 0), dis_from_destinataion(n, 0);
  auto bfs = [&](int src, auto &dist) {
    queue<int> q;
    q.emplace(src);
    dist[src] = 0;
    vector vis(n, false);
    vis[src] = false;
    while (q.size()) {
      auto u = q.front();
      q.pop();
      vis[u] = true;
      for (auto v : adj[u]) {
        if (vis[v])
          continue;
        dist[v] = dist[u] + 1;
        q.emplace(v);
      }
    }
  };
  int s, d;
  cin >> s >> d;
  bfs(s, dis_from_source);
  bfs(d, dis_from_destinataion);
  int ans(0);
  for (int i(0); i < n; ++i) {
    ans = max(ans, dis_from_destinataion[i] + dis_from_source[i]);
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int i(0); i < t; ++i) {
    cout << "Case " << i + 1 << ": ";
    solve();
  }
  return 0;
}
