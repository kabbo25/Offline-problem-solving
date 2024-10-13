#include <iostream>
#include<vector>
#include <array>
#include <algorithm>
#include <deque>
#include <cassert>
#include <map>

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

template<typename T, typename IdempotentBinaryOperation = const T &(*)(const T &, const T &)>
struct sparse_table {
    int SZ;
    IdempotentBinaryOperation TT;
    std::vector<std::vector<T>> data;

    sparse_table() {}

    sparse_table(IdempotentBinaryOperation _TT) : TT(_TT) {}

    template<typename Function>
    sparse_table(int _SZ, IdempotentBinaryOperation _TT, Function fn) : TT(_TT) {
        construct(_SZ, fn);
    }

    template<typename Function>
    void construct(int _SZ, Function fn) {
        SZ = _SZ;

        const int L = 32 - __builtin_clz(std::max(SZ - 1, 1));
        data.assign(L, std::vector<T>(SZ));

        for (int i = 0; i < SZ; i++)
            data[0][i] = fn(i);

        for (int l = 0; l + 1 < L; l++)
            for (int i = 0; i + (2 << l) <= SZ; i++)
                data[l + 1][i] = TT(data[l][i], data[l][i + (1 << l)]);
    }

    // Accumulates the elements at indices in [i, j) in O(1)
    T accumulate(int first, int last) const {
        assert(0 <= first && first < last && last <= SZ);
        int l = last - first > 1 ? 31 - __builtin_clz(last - first - 1) : 0;
        return TT(data[l][first], data[l][last - (1 << l)]);
    }
};

class Solution {
public:
    static vector<int> smallestRange(vector<vector<int>> &nums) {
        vector<array<int, 2>> sorted_list;
        int n = (int) nums.size();
        cout<<n<<endl;
        int need_mask = (1 << n) - 1;
        int mask = 0, mx = -2e9, mn = 2e9;
        for (int i(0); i < (int) nums.size(); ++i) {
            for (auto x: nums[i]) {
                sorted_list.push_back({x, i});
            }
        }
        sort(sorted_list.begin(), sorted_list.end());
        sparse_table<int> st_min((int) sorted_list.size(), std::min<int>, [&](int i) { return sorted_list[i][0]; });
        sparse_table<int> st_max((int) sorted_list.size(), std::max<int>, [&](int i) { return sorted_list[i][0]; });
         cout << sorted_list << endl;
        vector<int> res;
        auto reset = [&]() {
            mx = -2e9, mn = 2e9;
        };
        vector<int> ache(n);
        for (int i(0); i < n; ++i) {
            mask |= (1 << sorted_list[i][1]);
            mx = max(mx, sorted_list[i][0]);
            mn = min(mn, sorted_list[i][0]);
            ache[sorted_list[i][1]] = i;
        }
        if (mask == need_mask) {
            res.push_back(mn);
            res.push_back(mx);
            reset();
        }

        for (int i(n); i < (int) sorted_list.size(); ++i) {
            auto remove_mask = ~(1 << sorted_list.at(i - n)[1]);
            if (ache[sorted_list[i - n][1]] == i - n) {
                mask &= remove_mask;
                // dbg(remove_mask,ache,i);
            }
            ache[sorted_list[i][1]] = i;
            mask |= (1 << sorted_list[i][1]);
            if (mask == need_mask) {
                mn = st_min.accumulate(i - n + 1, i + 1);
                mx = st_max.accumulate(i - n + 1, i + 1);
                //dbg(mask,i,mn,mx);
                if (res.empty()) {
                    res.push_back(mn);
                    res.push_back(mx);
                    continue;
                }
                if (res[1] - res[0] > mx - mn) {
                    res[0] = (mn);
                    res[1] = (mx);
                    reset();
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> A{{11,38,83,84,84,85,88,89,89,92},{28,61,89},{52,77,79,80,81},{21,25,26,26,26,27},{9,83,85,90},{84,85,87},{26,68,70,71},{36,40,41,42,45},{-34,21},{-28,-28,-23,1,13,21,28,37,37,38},{-74,1,2,22,33,35,43,45},{54,96,98,98,99},{43,54,60,65,71,75},{43,46},{50,50,58,67,69},{7,14,15},{78,80,89,89,90},{35,47,63,69,77,92,94}};
    vector<vector<int>> B{{10, 10},
                          {11, 11}};
      cout << Solution::smallestRange(A) << endl;
  //  cout << Solution::smallestRange(B) << endl;
    return 0;
}
