#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n,0);
    for(int i(0);i<n;++i){
        cin>>nums[i];
    }
    map<int,int>freq;
    auto isDistinct = [&](auto val){
        return freq[val]==0;
    };
    int answer(0),distinct(0);
    for(int i(0);i<k;++i){
        if(isDistinct(nums.at(i)))
            distinct++;
        freq[nums.at(i)]++;
    }
    answer = distinct;
    for(int i(k);i<n;++i){
        freq[nums.at(i-k)]--;
        if(isDistinct(nums.at(i-k)))
            distinct--;
        if(isDistinct(nums.at(i)))
            distinct++;
        freq[nums.at(i)]++;
        answer=min(answer,distinct);
    }
    cout<<answer<<endl;
}

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   int t;
   cin>>t;
   while(t--){
       solve();
   }
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.