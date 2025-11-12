#include <string>

using std::string;

class Solution {
public:
    bool isValid(string s) {
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;

        for(auto c : s)
        {
            if(c == '(') ++cnt1;
            if(c == '[') ++cnt2;
            if(c == '{') ++cnt3;
        }

        return true;
    }
};