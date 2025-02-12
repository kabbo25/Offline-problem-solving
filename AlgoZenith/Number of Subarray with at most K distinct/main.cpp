#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>input(n,0);
    for(auto& x:input){
        cin>>x;
    }
    int64_t noOfSubarray(0);
    int tail(0),head(-1);
    int distinct(0);
    map<int,int>freq;
    auto isDistinct = [&](auto val){
        return freq[val]==0;
    };
    while(tail<n){
        while(head+1<n and (distinct<k or !isDistinct(input.at(head+1)))){
            head++;
            if(isDistinct(input.at(head))) {
                distinct++;
            }
            freq[input.at(head)]++;
        }
        noOfSubarray+=(head-tail+1);
        if(tail>head){
            tail++;
            head=tail-1;
        }
        else{
            freq[input.at(tail)]--;
            if(isDistinct(input.at(tail))){
                distinct--;
            }
            tail++;
        }
    }
    cout<<noOfSubarray<<endl;

}
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
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