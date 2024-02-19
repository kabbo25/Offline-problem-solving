#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    int n = heights.size();
    priority_queue<int> pq;
    for (int i(1); i < n; ++i) {
      auto now = heights[i] - heights[i - 1];
      pq.push(now);
      if (now <= 0)
        continue;
      if (bricks < now) {
        if (ladders == 0) {
          return i - 1;
        }
        ladders--;
        auto x = pq.top();
        pq.pop();
        bricks += x;
      }
      bricks -= now;
    }
    return n - 1;
  }
};
int main() {
  Solution obj;
  vector h{4, 2, 7, 6, 9, 14, 12};
  int bricks = 5;
  int ladders = 1;
  cout << obj.furthestBuilding(h, bricks, ladders) << endl;
}
