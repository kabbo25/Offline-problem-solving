#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cstdint>

using namespace std;

// Solution class where you'll implement your code
class Solution {
public:
    int numberOfSubstrings(string s) {
        int mask =0;
        int tail(0),head(-1);
        vector<int>freq(3,0);
        int64_t ans(0);
        int pivotPoint(-1);
        while(tail<(int)s.size()){

            while(head+1<(int)s.size() and mask<7){
                head++;
                freq[s.at(head)-'a']++;
                mask|=(1<<(s.at(head)-'a'));
                if(mask==7){
                    pivotPoint=head;
                    break;
                }
            }
            if(pivotPoint!=-1){
                ans+=((int)s.size()-pivotPoint);
            }
            if(tail>head){
                tail++;
                tail=head-1;
            }
            else{
                freq[s.at(tail)-'a']--;
                if(freq[s.at(tail)-'a']==0) {
                    mask &= (~(1 << (s.at(tail) - 'a')));
                    pivotPoint=-1;
                }
                tail++;
            }

        }
        return ans;
    }
};

// Test structure to hold test cases
struct TestCase {
    string input;
    int expected;
    string description;

    TestCase(string i, int e, string d) : input(i), expected(e), description(d) {}
};

// Function to run tests
void runTests(vector<TestCase>& tests) {
    Solution solution;
    bool allPassed = true;
    int testNumber = 1;

    for (const TestCase& test : tests) {
        int result = solution.numberOfSubstrings(test.input);
        bool passed = (result == test.expected);
        allPassed &= passed;

        cout << "Test " << testNumber << ": " << (passed ? "PASSED" : "FAILED") << endl;
        cout << "Input: \"" << test.input << "\"" << endl;
        cout << "Expected: " << test.expected << endl;
        cout << "Got: " << result << endl;
        cout << "Description: " << test.description << endl;
        cout << "----------------------------------------" << endl;

        testNumber++;
    }

    if (allPassed) {
        cout << "All tests passed!" << endl;
    } else {
        cout << "Some tests failed. Please check your implementation." << endl;
    }
}

int main() {
    vector<TestCase> tests = {
           // TestCase("abcabc", 10, "Example 1: Multiple occurrences of a, b, and c"),
            TestCase("aaacb", 3, "Example 2: String with repeated characters"),
            TestCase("abc", 1, "Example 3: Basic case with exactly one occurrence each"),
            // Additional test cases for edge cases
            TestCase("", 0, "Edge case: Empty string"),
            TestCase("ab", 0, "Edge case: Missing character c"),
            TestCase("aaa", 0, "Edge case: Only one type of character"),
            TestCase("abcabcabc", 28, "Complex case: Multiple patterns")
    };

    runTests(tests);
    return 0;
}