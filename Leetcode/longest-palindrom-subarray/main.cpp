#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        vector<int>dp(n+5,0);
        for(int i(0);i<n;++i){
            if(s[i]==')'){
                auto prev=i-1;
                if(i-1>=0 and s[i-1]=='('){
                    dp[i]=2+(i-2>=0 ? dp[i-2]:0);
                }
                else{
                    if(i-1<0)continue;

                    int idx=i-dp[i-1]-1;
                    if(idx>=0 and s[idx]=='('){
                        dp[i]=2+(idx-1>=0?dp[idx-1]:0);
                        dp[i]+=(i-1>=0? dp[i-1]: 0);
                    }
                }
            }
        }
//        for(int i(0);i<n;++i){
//            cout<<dp[i]<<" "<<' ';
//        }
        return *max_element(dp.begin(),dp.end());
    }
};

int main() {
    Solution solution;

    // Test cases
//    string test1 = "()()";
//    cout << "Test 1: s = \"" << test1 << "\"" << endl;
//    cout << "Output: " << solution.longestValidParentheses(test1) << endl;
//
//    string test2 = "(()";
//    cout << "Test 2: s = \"" << test2 << "\"" << endl;
//    cout << "Output: " << solution.longestValidParentheses(test2) << endl;
//
//    string test3 = ")()())";
//    cout << "Test 3: s = \"" << test3 << "\"" << endl;
//    cout << "Output: " <<; solution.longestValidParentheses(test3) << endl;

    string test4 = "()(())";
    cout << "Test 4: s = \"" << test4 << "\"" << endl;
    cout << "Output: " << solution.longestValidParentheses(test4) << endl;

    return 0;
}