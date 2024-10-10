#include <iostream>
#include <vector>
#include <map>

using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>& t) { os << '('; apply([&os](const Args&... args) { size_t n = 0; ((os << args << (++n != sizeof...(Args) ? ", " : "")), ...); }, t); return os << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}
class Solution {
public:
    static vector<int> anagramMappings(vector<int> &nums1, vector<int> &nums2) {
        map<int,vector<int>>pos;
        int n= (int)nums1.size();
        for(int i(0);i<n;++i){
            pos[nums2[i]].push_back(i);
        }
        vector<int>result(n,-1);
        for(int i(n-1);i>=0;--i){
            result[i]=pos[nums1[i]].back();
            pos[nums1[i]].pop_back();
        }
        return result;
    }
};

int main() {
    vector<int> A{12, 28, 46, 32, 50};
    vector<int> B{50, 12, 32, 46, 28};
    vector<int> C{84, 46};
    vector<int> D{84, 46};
    output_vector(Solution::anagramMappings(A,B));
    output_vector(Solution::anagramMappings(C,D));

    return 0;
}
