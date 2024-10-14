#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    static int missingNumber(vector<int>& arr) {
        vector<int>diff;
        for(int i(1);i<(int)arr.size();++i){
           diff.emplace_back(arr[i]-arr[i-1]) ;
        }
        sort(diff.begin(),diff.end(),[](auto x,auto y){
            return abs(x)<abs(y);
        });
        for(int i(1);i<arr.size();++i){
            int cur_diff=arr[i]-arr[i-1];
            if(cur_diff!=diff.front()){
                return arr[i]-diff.front();
            }
        }
        return arr.front();
    }
};
int main() {
    vector<int>A{5,7,11,13};
    vector<int>B{15,13,12};
    cout<<Solution::missingNumber(A)<<endl;
    cout<<Solution::missingNumber(B)<<endl;
    return 0;
}
