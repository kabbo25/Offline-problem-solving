#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
bool seen[MAX];
int freq[MAX];
void solve(){
    int N;
    cin>>N;
    vector<int>nums(N,0);
    int totalDistinct(0),distinct(0);
    //clearing the state
    for(int i(0);i<MAX;++i){
        seen[i]=false;
        freq[i]=0;
    }
    for(int i(0);i<N;++i){
        cin>>nums[i];
        if(!seen[nums.at(i)]){
            totalDistinct++;
        }
        seen[nums.at(i)]=true;
    }
   int tail(0),head(-1);
    int shortestSubstring(MAX);
    while(tail<N){
        while(head+1<N and distinct<totalDistinct){
            head++;
            if(freq[nums.at(head)]==0){
               distinct++;
            }
            freq[nums.at(head)]++;
        }
        if(distinct==totalDistinct)
            shortestSubstring = min(shortestSubstring, head-tail+1);
        if(tail>head){
            tail++;
            head=tail-1;
        }
        else{
            freq[nums.at(tail)]--;
            if(!freq[nums.at(tail)])
                distinct--;
            tail++;
        }
    }
    cout<<shortestSubstring<<endl;
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