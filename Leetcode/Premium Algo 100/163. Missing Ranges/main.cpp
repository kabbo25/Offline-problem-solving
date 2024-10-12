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
            if (nums.empty()) {
                return {{lower, upper}};
            }
            nums.insert(nums.begin(), lower);
            nums.emplace_back(upper);
            for (int i(0); i < (int) nums.size(); ++i) {
                if (nums[i] - left <= 1) {
                    left = nums[i];
                    continue;
                }
                if (i == 0) {
                    res.push_back({left, nums[i] - 1});
                    left = nums[i];
                    continue;
                }
                if (i == (int) nums.size() - 1) {
                    res.push_back({left + 1, nums[i]});
                    continue;
                }
                res.push_back({left + 1, nums[i] - 1});
                left = nums[i];
            }
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
