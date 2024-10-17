#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        int mx=num;
        for(int i(0);i<n;++i){
            for(int j(i);j<n;++j){
                string temp=s;
                swap(temp[i],temp[j]);
                int cur=stoi(temp);
                mx=max(mx,cur);
            }
        }
        return mx;
    }
};