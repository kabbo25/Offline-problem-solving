#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool canAttendMeetings(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(),[](auto x,auto y){
            return x[1] <y[1];
        });
        bool canAttend = true;
        for(int i(1);i<intervals.size();i++){
            canAttend&= (intervals[i][0] >= intervals[i-1][1]);
        }
        return canAttend;
    }
};


// Test function
void runTest(vector<vector<int>> &intervals, bool expectedOutput)
{
    Solution solution;
    bool result = solution.canAttendMeetings(intervals);

    cout << "Input: [";
    for (size_t i = 0; i < intervals.size(); i++)
    {
        cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]";
        if (i < intervals.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;

    cout << "Output: " << (result ? "true" : "false") << endl;
    cout << "Expected: " << (expectedOutput ? "true" : "false") << endl;
    cout << "Result: " << (result == expectedOutput ? "PASSED" : "FAILED") << endl;
    cout << "------------------------" << endl;
}

int main()
{
    // Test Case 1
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    runTest(intervals1, false);

    // Test Case 2
    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};
    runTest(intervals2, true);

    // Additional Test Case - Empty intervals
    vector<vector<int>> intervals3 = {};
    runTest(intervals3, true);

    // Additional Test Case - Single interval
    vector<vector<int>> intervals4 = {{1, 5}};
    runTest(intervals4, true);

    return 0;
}