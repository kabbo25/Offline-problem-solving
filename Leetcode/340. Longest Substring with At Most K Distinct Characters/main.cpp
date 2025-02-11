#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstringKDistinct(const string &s, int k) {

        // Your implementation here
        int tail(0), head(-1), size((int) s.size());
        map<char, int> freq;
        int distinct(0);
        int longest_length(0);
        while (tail < size) {
            // condition to move head
            while (head + 1 < size and (distinct < k or freq[s.at(head+1)] > 0)) {
                head++;
                if (freq[s.at(head)] == 0) {
                    distinct++;
                }
                freq.at(s.at(head))++;
            }
            longest_length = max(longest_length, head - tail + 1);
            if (tail > head) {
                tail++;
                head = tail - 1;
            } else {
                freq[s.at(tail)]--;
                if (freq[s.at(tail)] == 0) {
                    distinct--;
                }
                tail++;
            }
        }

        return longest_length;
    }
};

void runTest(const string &testName, const string &s, int k, int expected) {
    Solution solution;
    int result = Solution::lengthOfLongestSubstringKDistinct(s, k);

    cout << testName << ": ";
    if (result == expected) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
        cout << "Input: s = \"" << s << "\", k = " << k << endl;
        cout << "Expected: " << expected << ", Got: " << result << endl;
    }
}

int main() {
    // Test Case 1 from example
    runTest("Example 1", "eceba", 2, 3);

    // Test Case 2 from example
    runTest("Example 2", "aa", 1, 2);

    // Additional validation test cases
    runTest("Empty String", "", 1, 0);
    runTest("Single Character", "a", 1, 1);
    runTest("K = 0", "abc", 0, 0);
    runTest("All Same Characters", "aaaa", 1, 4);
    runTest("K Greater Than String Length", "abc", 5, 3);

    return 0;
}