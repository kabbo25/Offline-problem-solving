#include <iostream>
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>& t) { os << '('; apply([&os](const Args&... args) { size_t n = 0; ((os << args << (++n != sizeof...(Args) ? ", " : "")), ...); }, t); return os << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef NEAL_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
class Solution {
public:
    static string compressedString(string word) {
        char prev=word[0];
        int cnt=-1;
        word+='$';
        string res;
        auto process=[&](){
            while(true) {
                int can = min(9, cnt);
                if (!can)return;
                dbg(can);
                res += char(can + '0');
                res += prev;
                cnt -= can;
                if (cnt) {
                    res += char(cnt + '0');
                    res += prev;
                }
            }
        };
        for(int i(0);i<(int)word.length();++i){
            cnt++;
            if(word[i]!=prev){
                process();
            }

            prev=word[i];
        }
        //process();
        return res;
    }
};

int main() {
    cout<<Solution::compressedString("aaaaaaaaaaaaaabb")<<endl;
    return 0;
}
