#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> rearrangeArray(vector<int> &nums) {
    deque<int> dq;
    int n = nums.size(), cnt = 0;
    for (int i(0); i < n; ++i) {
      if (nums[i] < 0)
        dq.emplace_back(nums[i]);
      else {
        nums[cnt++] = nums[i];
      }
    }
    bool flag(true);
    for (int i(1); i < n; ++i) {
      if (flag) {
        dq.emplace_back(nums[i]);
        nums[i] = dq.front();
        dq.pop_front();
      } else {
        int temp = nums[i];
        if (dq.back() > 0)
          nums[i] = dq.back();
        dq.pop_back();
        dq.emplace_back(temp);
      }
      flag ^= 1;
    }
    return nums;
  }
};
int main() {
  Solution obj;
  vector<int> v{-1, 1};
  auto p = obj.rearrangeArray(v);
  for (int i = 0; i < (int)p.size(); i++) {
    cout << p[i] << ' ' << endl;
  }
}
