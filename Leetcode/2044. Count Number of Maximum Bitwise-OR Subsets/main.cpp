#include <bits/stdc++.h>
#include <functional>
using namespace std;

class Solution {
public:
  int countMaxOrSubsets(vector<int> &nums) {
    map<int64_t, int, greater<>> maxOr;
    int n = nums.size();
    for (int mask(0); mask < (1 << n); ++mask) {
      int64_t currentOr = 0;
      for (int i(0); i < n; ++i) {
        if (mask >> i & 1)
          currentOr |= nums[i];
      }
      maxOr[currentOr]++;
    }
    return maxOr.begin()->second;
  }
};