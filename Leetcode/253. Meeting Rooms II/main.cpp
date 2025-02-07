#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](auto x,auto y){
            return x[1]<y[1];
        });
        int count(1);
        for(int i(1);i<intervals.size();i++){
            if(intervals[i][0]<intervals[i-1][1]){
                count++;

            }
        
        }
       return count;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    cout << "Test Case 1:" << endl;
    cout << "Input: [[0,30],[5,10],[15,20]]" << endl;
    cout << "Output: " << solution.minMeetingRooms(intervals1) << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Test Case 2
    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};
    cout << "Test Case 2:" << endl;
    cout << "Input: [[7,10],[2,4]]" << endl;
    cout << "Output: " << solution.minMeetingRooms(intervals2) << endl;
    cout << "Expected: 1" << endl;
    
    return 0;
} 