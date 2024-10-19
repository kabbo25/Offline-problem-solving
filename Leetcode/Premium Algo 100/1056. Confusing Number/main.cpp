#include <iostream>
using namespace std;
class Solution {
public:
    bool confusingNumber(int n) {
        string s= to_string(n);
        string temp=s;
        for(int i((int)s.length()-1);i>=0;--i){
            if(s[i]=='9')temp+='6';
            else if(s[i]=='6')temp+='9';
            else temp+=s[i];
        }
        auto valid=[&](auto x){
          return s.find(x)!=string::npos;
        };
        auto ache= true;
        for(auto x:{'2','3','4','5','7'}){
            ache&=(!valid(x));
        }
        return ache and (s!=temp);
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
