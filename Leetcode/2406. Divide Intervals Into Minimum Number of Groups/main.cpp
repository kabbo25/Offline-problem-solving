#include <iostream>
#include<vector>
#include <algorithm>
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
    static int minGroups(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        multiset<int> groups;
        for (auto &interval: intervals) {
            auto st = interval[0], ed = interval[1];
            if (groups.empty()) {
                groups.emplace(ed);
                continue;
            }
            auto it = groups.lower_bound(st);
            if (it == groups.begin()) {
                groups.emplace(ed);
            } else {
                it = prev(it);
                groups.erase(it);
                groups.emplace(ed);
            }
            //dbg(interval,groups);
        }
        return (int) groups.size();
    }
};

int main() {
    vector<vector<int>> A{{5, 10},
                          {6, 8},
                          {1, 5},
                          {2, 3},
                          {1, 10}};
    vector<vector<int>> B{{1, 3},
                          {5, 6},
                          {8, 10},
                          {11, 13}};
    cout << Solution::minGroups(A) << endl;
    cout << Solution::minGroups(B) << endl;
    return 0;
}
