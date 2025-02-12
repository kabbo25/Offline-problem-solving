#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>nums(n,0);
    for(auto& x:nums)
        cin>>x;
    int tail(0),head(-1);
    map<int,int>freq;
    int longestLength(0);
    auto isDistinct = [&](auto val){
        return freq[val]==0;
    };
    while(tail<n){
       while(head+1<n and isDistinct(nums.at(head+1))) {
           head++;
           freq[nums.at(head)]++;
       }
       longestLength= max(longestLength,head-tail+1);
       if(tail>head){
           tail++;
           head=tail-1;
       }
       else{
           --freq[nums.at(tail)];
           tail++;
       }
    }
    cout<<longestLength<<endl;
}
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for(int i(0);i<t;++i){
        solve();
    }
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.