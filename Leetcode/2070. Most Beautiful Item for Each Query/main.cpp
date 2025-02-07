#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
    sort(items.begin(), items.end());
    vector<int> prefix_max(1, items[0][1]);
    for (int i(1); i < (int)items.size(); ++i) {
      prefix_max.emplace_back(max(prefix_max.back(), items[i][1]));
    }
    vector<int> ans;
    for (int i : queries) {
      auto it = upper_bound(items.begin(), items.end(), vector{i, (int)1e9});
      if (it == items.begin()) {
        ans.emplace_back(0);
        continue;
      }
      it--;
      auto idx = (it - items.begin());
      ans.emplace_back(prefix_max[idx]);
      cout << endl;
    }
    return ans;
  }
};