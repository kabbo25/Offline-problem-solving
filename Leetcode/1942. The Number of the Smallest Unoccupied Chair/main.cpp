#include <iostream>
#include<vector>
#include <queue>
#include<array>
#include <algorithm>
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

class Solution {
public:
    static int smallestChair(vector<vector<int>> &times, int targetFriend) {
        priority_queue<int,vector<int>,greater<>> pq;
        vector<array<int, 2>> arrival, leaving;
        int mx = 0;
        for (int i(0); i < (int) times.size(); ++i) {
            arrival.push_back({times[i][0], i});
            leaving.push_back({times[i][1], i});
            mx = max({mx, times[i][0], times[i][1]});
        }
        sort(arrival.begin(), arrival.end());
        sort(leaving.begin(), leaving.end());
        map<int, int> sittingPosition;
        for (int i(0); i <= mx; ++i)pq.emplace(i);
        for (int i(0); i <= mx; ++i) {
            auto it = lower_bound(leaving.begin(), leaving.end(), array<int, 2>{i, (int) -1e9});
            if (it != leaving.end() and (*it)[0] == i) {
                auto [time, idx] = *it;
                pq.emplace(sittingPosition[idx]);
               // sittingPosition.erase(idx);
                //currentChair--;
                //    dbg(time,idx,i);
            }
            auto it1 = lower_bound(arrival.begin(), arrival.end(), array<int, 2>{i, (int) -1e9});
            if (it1 != arrival.end() and (*it1)[0] == i) {
                auto [time, idx] = *it1;
               // dbg(time,idx,i,pq.top());
                sittingPosition[idx] = pq.top();
                pq.pop();
            }
        }
        return sittingPosition[targetFriend];
    }
};

int main() {
    vector<vector<int>> A{{1, 4},
                          {2, 3},
                          {4, 6}};
    vector<vector<int>> B{{3, 10},
                          {1, 5},
                          {2, 6}};
    cout << Solution::smallestChair(A, 1) << endl;
    cout << Solution::smallestChair(B, 0) << endl;
    return 0;
}
