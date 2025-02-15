#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,vector<int>>position;
    for(int i(0);i<n;++i){
        if(!position.count(s.at(i)))
            position[s.at(i)].emplace_back(-1);
        position[s.at(i)].emplace_back(i);
    }
    for(int i(0);i<26;++i){
        position[char('a'+i)].emplace_back(n);
    }
    int64_t answer(0);
    for(int i(0);i<n;++i){
        auto currentChar= s[i];
        auto index= lower_bound(position[currentChar].begin(),position[currentChar].end(),i)-position[currentChar].begin();
        int  left= position[currentChar][index]-position[currentChar][index-1];
        int right = position[currentChar][index+1]-position[currentChar][index];
        answer+=(1LL*left*right);
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