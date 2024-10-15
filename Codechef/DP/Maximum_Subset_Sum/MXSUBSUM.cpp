#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector v(n, 0);
  for (int i(0); i < n; ++i) {
    cin >> v[i];
  }
  vector<int>dp(n+1,0);
  auto relax=[](int& a,int b){
  	a=max(a,b);
  };
  for(int i(0);i<n;++i){
    vector new_dp = dp;
    if(i==0)relax(dp[i],v[0]);
    else{
      dp[i]=max(dp[i-1],dp[i-1]+v[i]);
    }
  }
  cout<<dp[n-1]<<endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i(0); i < t; ++i) {
    solve();
  }
}
