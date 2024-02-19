#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> rearrangeArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n);
    int pos(0), neg(1);
    for (auto x : nums) {
      if (x > 0) {
        ans[pos] = x;
        pos += 2;
      } else {
        ans[neg] = x;
        neg += 2;
      }
    }
    return ans;
  }
};
int main() {
  Solution obj;
  vector<int> v{3, 1, -2, -5, 2, -4};
  auto p = obj.rearrangeArray(v);
  for (int i = 0; i < (int)p.size(); i++) {
    cout << p[i] << ' ' << endl;
  }
}
