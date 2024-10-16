#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
            string res;
            priority_queue<pair<int,char>>pq;
            pq.emplace(a,'a');        
            pq.emplace(b,'b');        
            pq.emplace(c,'c');
            char prev='#';
            while(pq.size()){
                auto [value_top,current_char_top]=pq.top();
                pq.pop();
                if(value_top<=0)continue;
                if(current_char_top!=prev){
                    //cout<<current_char<<" "<<prev<<" "<<value<<endl;
                    res+=string(min(2,value_top),current_char_top);
                    value_top-=2;
                    if(value_top>0)
                        pq.emplace(value_top,current_char_top);
                        prev=current_char_top;
                }
                else{
                    
                    if(pq.empty())break;
                    auto [value,current_char]=pq.top();pq.pop();
                    if(value<=0)continue;
                    pq.emplace(value_top,current_char_top);
                    //cout<<value<<" "<<current_char<<endl;
                    res+=current_char;
                    value--;
                    if(value>0)pq.emplace(value,current_char);
                    prev=current_char;
                }
                
            }
            return res;
    
    }
};

