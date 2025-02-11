#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <cstdint>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int> &nums, int k) {
        // Your implementation here
        int tail(0), head(-1), size((int) nums.size());
        map<int, int> freq;
        int distinct(0);
        int64_t noOfSubarray(0);
        while (tail < size) {
            int startOfValidSubarray(head);
            while (head + 1 < size and (distinct < k or freq[nums.at(head + 1)] > 0)) {
                head++;
                if (freq[nums.at(head)] == 0) {
                    distinct++;
                    if (distinct == k) {
                        startOfValidSubarray = head;
                    }
                }
                freq[nums.at(head)]++;
            }
            cout<<head<<" "<<" "<<tail<<" "<<startOfValidSubarray<<" "<<distinct<<endl;
            if (distinct == k)
                noOfSubarray += (head - startOfValidSubarray + 1);
            if (tail > head) {
                tail++;
                head = tail - 1;
            } else {
                freq[nums.at(tail)]--;
                if (freq[nums.at(tail)] == 0) {
                    distinct--;
                }
                tail++;
            }
        }
        return noOfSubarray; // Placeholder return
    }
};

void runTestCase(vector<int> &nums, int k, int expected, int testCaseNumber) {
    Solution solution;
    int result = solution.subarraysWithKDistinct(nums, k);

    cout << "Test Case " << testCaseNumber << ":\n";
    cout << "Input array: [";
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]\n";
    cout << "k = " << k << "\n";
    cout << "Expected output: " << expected << "\n";
    cout << "Your output: " << result << "\n";

    if (result == expected) {
        cout << "Status: PASSED\n";
    } else {
        cout << "Status: FAILED\n";
    }
    cout << "------------------------\n";
}

int main() {
    // Test Case 1
    vector<int> nums1 = {1, 2, 1, 2, 3};
    int k1 = 2;
    int expected1 = 7;
    runTestCase(nums1, k1, expected1, 1);

//    // Test Case 2
//    vector<int> nums2 = {1, 2, 1, 3, 4};
//    int k2 = 3;
//    int expected2 = 3;
//    runTestCase(nums2, k2, expected2, 2);
//
//    // Additional Test Case 3 - Edge case with k = 1
//    vector<int> nums3 = {1, 1, 1};
//    int k3 = 1;
//    int expected3 = 6;  // [1], [1], [1], [1,1], [1,1], [1,1,1]
//    runTestCase(nums3, k3, expected3, 3);
//
//    // Additional Test Case 4 - Edge case with k equal to array size
//    vector<int> nums4 = {1, 2, 3, 4};
//    int k4 = 4;
//    int expected4 = 1;  // Only [1,2,3,4] has exactly 4 distinct integers
//    runTestCase(nums4, k4, expected4, 4);
//
//    // Additional Test Case 5 - Array with all same numbers
//    vector<int> nums5 = {2, 2, 2, 2};
//    int k5 = 1;
//    int expected5 = 10;  // All possible subarrays have exactly 1 distinct integer
//    runTestCase(nums5, k5, expected5, 5);

    return 0;
}