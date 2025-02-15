#include<bits/stdc++.h>
using namespace std;

void solve(){
    int64_t N,target;
    cin>>N>>target;
    vector<int64_t>nums(N,0);
    for(int i(0);i<N;++i){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    int64_t answer = 9e18;
    for(int j(1);j+1<N;++j){
        //fixed j
        int64_t i=0,k=N-1;
        while(i<j and j<k){
            int64_t curSum = nums[i]+nums[k]+nums[j];
            answer=min(answer, abs(target-curSum));
            if(curSum<=target)
                i++;
            else k--;
        }
    }
    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}