#include <iostream>

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
    static char findKthBit(int n, int k) {
        string res = "0";
        for (int i(1); i <= n; ++i) {
            string temp = res;
            temp += '1';
            for (int j = (int) res.length() - 1; j >= 0; --j)
                temp += (res[j] == '0' ? '1' : '0');
            res = temp;
            //dbg(temp, i);
        }
        return res[k - 1];
    }
};

int main() {
    cout << Solution::findKthBit(3, 1) << endl;
    cout << Solution::findKthBit(4, 11) << endl;
    return 0;
}
