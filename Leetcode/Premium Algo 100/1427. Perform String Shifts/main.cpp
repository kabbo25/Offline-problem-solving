#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   static string stringShift(string s, vector<vector<int>>& shift) {
        int n=(int)s.length();
        for(auto& x:shift){
            x[1]%=n;
            if(!x[0]) {
                rotate(s.begin(), s.begin() + x[1], s.end());
                cout<<s<<endl;
            }
            else {
                rotate(s.begin(),s.begin()+n-x[1],s.end());
                cout<<s<<endl;
            }
        }
         return s;
    }
};
int main(){

    string s="abc";
    vector<vector<int>>v({{0,1},{1,2}});
    cout<<Solution::stringShift(s,v);
}