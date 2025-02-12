#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
      int answer(0);
      for(int i(0);i<26;++i){
          answer = max(answer, lengthOfLongestSubstringWithFixedCharacter(s,k,char('A'+i)));
      }
      return answer;
    }
    int lengthOfLongestSubstringWithFixedCharacter(string& s,int k,char target){
       int N= s.size();
       int tail(0),head(-1);
       int longestLength(0);
       map<char,int>freq;
       auto isNewInsertPossible = [&](auto ch){
           int currentLength = (head-tail+2);
           int remainCharacter = currentLength-(freq[target]+(ch==target));
           return remainCharacter<=k;
       };
       while(tail<N){
           while(head+1<N and isNewInsertPossible(s[head+1])){
               head++;
               freq[s[head]]++;
           }
           longestLength = max(longestLength,head-tail+1);
           if(tail>head){
               tail++;
               head=tail-1;
           }
           else{
               --freq[s[tail]];
               tail++;
           }
       }
       return longestLength;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    string test1 = "ABAB";
    int result1 = solution.characterReplacement(test1,2);
    cout << "Test Case 1: " << (result1 == 3 ? "PASSED" : "FAILED") << endl;
    cout << "Input: \"" << test1 << "\"" << endl;
    cout << "Expected: 4" << endl;
    cout << "Got: " << result1 << endl << endl;



    cout << "All test cases completed!" << endl;
    return 0;
}