#include <iostream>
#include <vector>

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

#ifdef NEAL_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

class Solution {
public:
    static vector<vector<int>> findMissingRanges(vector<int> &nums, int lower, int upper) {
        {
            int left = lower;
            vector<vector<int>> res;
            if(nums.empty()){
                return {{lower,upper}};
            }
            if(lower!=nums.front()){
                res.push_back({lower,nums.front()-1});
                left=nums.front();
            }
            for (int num : nums) {
                if (num - left <= 1) {
                    left = num ;
                    continue;
                }
                res.push_back({left+1, num - 1});
                left = num;
            }
            if(nums.back()!=upper)
                res.push_back({nums.back()+1,upper});
            return res;
        }
    }
};

int main() {
    vector<int> A{0, 1, 3, 50, 75};
    vector<int> B{-1};
    cout << Solution::findMissingRanges(A, 0, 99) << endl;
    cout << Solution::findMissingRanges(B, -2, -1) << endl;
    return 0;
}
