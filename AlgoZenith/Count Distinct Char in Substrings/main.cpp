#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int64_t answer(0);
    for(char ch='a';ch<='z';++ch){
        int lastOccur=-1;
        for(int i(0);i<n;++i){
            if(s[i]==ch){
                answer+=(i+1);
                lastOccur=i;
            }
            else{
                answer+=(lastOccur+1);
            }
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