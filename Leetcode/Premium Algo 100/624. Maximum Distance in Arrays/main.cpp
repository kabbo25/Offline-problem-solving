#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    static int maxDistance(vector<vector<int>>& arrays) {
        {
            vector<pair<int, int>> first,last;
            int idx(0);
            for (auto &row: arrays) {
                sort(row.begin(), row.end());
                first.emplace_back(row[0], idx);
                last.emplace_back(row.back(),idx++);
            }
            sort(first.begin(),first.end());
            sort(last.rbegin(),last.rend());
            if(first.size()==1){
                return 0;
            }
            int ans=last.front().first-first.front().first;
            // cerr<<ans<<endl;
            if(first.front().second==last.front().second){
                ans=abs(first.front().first- last[1].first);
            }
            ans=max(ans,last.front().first-first[1].first);
            return ans;
        }
    }
};

int main() {
    vector<vector<int>> A{{1, 2, 3},
                          {4, 5},
                          {1, 2, 3}};
    vector<vector<int>> B {{1,4},{0,5}};
    cout << Solution::maxDistance(A) << endl;
    cout << Solution::maxDistance(B) << endl;

    return 0;
}
