#include <iostream>
#include<vector>
#include <array>
#include <algorithm>
#include <deque>
#include <cassert>
#include <set>

using namespace std;

template<typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

template<typename... Args>
ostream &operator<<(ostream &os, const tuple<Args...> &t) {
    os << '(';
    apply([&os](const Args &... args) {
        size_t n = 0;
        ((os << args << (++n != sizeof...(Args) ? ", " : "")), ...);
    }, t);
    return os << ')';
}

template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x: v) os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() { cerr << endl; }

template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}

#ifndef NEAL_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
class Solution {
public:
    static vector<int> smallestRange(vector<vector<int>> &nums){
        set<array<int,3>>heap;
        int n=(int)nums.size();
        for(int i(0);i<n;++i){
            heap.insert({nums[i][0],i,0});
        }
        vector<int>res;
        res.push_back((*heap.begin())[0]);
        res.push_back((*heap.rbegin())[0]);
        while(true){
            if(heap.size()<n)break;
            auto [min_value,current_list,current_idx]=*heap.begin();
            auto max_value= (*heap.rbegin())[0];
            if(max_value-min_value<=res.back()-res.front()){
                if(max_value-min_value==res.back()-res.front()){
                    if(min_value<res.front() ){
                        res[0]=min_value;
                        res[1]=max_value;
                    }
                }
                else{
                    res[0]=min_value;
                    res[1]=max_value;
                }
            }
            heap.erase(heap.begin());
            if(current_idx+1<(int)nums[current_list].size()){
                current_idx++;
                heap.insert({nums[current_list][current_idx],current_list,current_idx});
            }

        }
        return res;
    }
};

int main() {
    vector<vector<int>> A{{11,38,83,84,84,85,88,89,89,92},{28,61,89},{52,77,79,80,81},{21,25,26,26,26,27},{9,83,85,90},{84,85,87},{26,68,70,71},{36,40,41,42,45},{-34,21},{-28,-28,-23,1,13,21,28,37,37,38},{-74,1,2,22,33,35,43,45},{54,96,98,98,99},{43,54,60,65,71,75},{43,46},{50,50,58,67,69},{7,14,15},{78,80,89,89,90},{35,47,63,69,77,92,94}};
    vector<vector<int>> B{{-5,-4,-3,-2,-1},{1,2,3,4,5}};
      //cout << Solution::smallestRange(A) << endl;
    cout << Solution::smallestRange(B) << endl;
    return 0;
}
