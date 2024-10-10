#include <iostream>
#include<vector>
#include <stack>

using namespace std;
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        //monotonic stack
        stack<int>st;
        for(int i(0);i<(int)nums.size();++i){
            if(st.empty() or nums[st.top()]>nums[i])
                st.emplace(i);
        }
        int mx=0;
        for(int i((int)nums.size()-1);i>=0;--i){
           while(!st.empty() and nums[i]>=nums[st.top()]){
               mx=max(mx,i-st.top());
               st.pop();
           }
        }
        return mx;

    }
};
int main() {
    vector<int>A{6,0,8,2,1,5};
    vector<int>B{9,8,1,0,1,9,4,0,4,1};
    Solution sol;
    cout<<sol.maxWidthRamp(A)<<endl;
    cout<<sol.maxWidthRamp(B)<<endl;
    return 0;
}
